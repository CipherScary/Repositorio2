#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>

// Função para gerar uma letra aleatória entre 'A' e 'Z'
char gerarLetraAleatoria() {
    return 'A' + rand() % 26;
}

// Função para verificar se uma letra está presente na palavra
bool verificarLetraNaPalavra(const std::string& palavra, char letra) {
    return palavra.find(letra) != std::string::npos;
}

int main() {
    srand(time(0));
    
    const int limiteTentativas = 6; // Número máximo de tentativas
    const std::string palavras[] = {"SENHOR DOS ANEIS", "HOMEM DE FERRO", "TOYSTORY", "MONSTROS SA", "SUPER MARIO BROS O FILME"}; // Lista de palavras possíveis
    const int quantidadePalavras = sizeof(palavras) / sizeof(palavras[0]);
    
    // Escolhe uma palavra aleatória da lista
    std::string palavraEscolhida = palavras[rand() % quantidadePalavras];
    
    std::string palavraAdivinhada(palavraEscolhida.length(), '_'); // Inicializa a palavra a ser adivinhada com underscores
    int tentativas = 0; // Contador de tentativas
    
    std::cout << "Bem-vindo ao jogo Super Forca!" << std::endl;
    
    // Loop para as tentativas do jogador
    while (tentativas < limiteTentativas) {
        std::cout << "Palavra a adivinhar: " << palavraAdivinhada << std::endl;
        std::cout << "Tentativa #" << (tentativas + 1) << ": ";
        char chute;
        std::cin >> chute;
        chute = std::toupper(chute); // Converte o chute para maiúscula
        
        if (verificarLetraNaPalavra(palavraEscolhida, chute)) {
            // Atualiza a palavra adivinhada com as letras corretas
            for (size_t i = 0; i < palavraEscolhida.length(); i++) {
                if (palavraEscolhida[i] == chute) {
                    palavraAdivinhada[i] = chute;
                }
            }
            // Verifica se a palavra foi completamente adivinhada
            if (palavraAdivinhada == palavraEscolhida) {
                std::cout << "Parabéns! Você adivinhou a palavra: " << palavraEscolhida << std::endl;
                break;
            }
        } else {
            std::cout << "Chute errado. Tente novamente." << std::endl;
            tentativas++;
        }
    }
    
    // Exibe mensagem de resultado caso o jogador tenha usado todas as tentativas
    if (tentativas == limiteTentativas) {
        std::cout << "Suas tentativas acabaram. A palavra era: " << palavraEscolhida << std::endl;
    }
    
    return 0; // Indica que o programa foi executado com sucesso
}