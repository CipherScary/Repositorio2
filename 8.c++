#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring> // Incluindo a biblioteca cstring para usar strchr

// Função para gerar uma letra aleatória entre 'A' e 'Z'
char gerarLetraAleatoria() {
    return 'A' + rand() % 26;
}

int main() {
    srand(time(0)); // Inicializa o gerador de números aleatórios com o valor do tempo atual
    
    char letraSorteada = gerarLetraAleatoria(); // Gera uma letra aleatória
    const int limiteTentativas = 5; // Define o número máximo de tentativas
    int tentativas = 0; // Contador de tentativas
    
    char chute;
    bool acertou = false;
    
    std::cout << "Uma letra aleatoria foi sorteada! Tente adivinhar." << std::endl;

    // Verifica se a letra sorteada é uma vogal ou consoante e exibe uma dica
    std::string dica = std::strchr("AEIOU", letraSorteada) ? "vogal" : "consoante";
    std::cout << "Dica: A letra sorteada é uma " << dica << "." << std::endl;

    while (tentativas < limiteTentativas) {
        std::cout << "Tentativa #" << (tentativas + 1) << ": ";
        std::cin >> chute;
        chute = std::toupper(chute); // Converte o chute para maiúsculas
        
        if (chute == letraSorteada) {
            acertou = true;
            break;
        } else {
            std::cout << "Chute errado. Tente novamente." << std::endl;
            tentativas++;
        }
    }
    
    std::cout << "A letra sorteada era: " << letraSorteada << std::endl;
    
    if (acertou) {
        std::cout << "Parabens! Voce acertou a letra em " << (tentativas + 1) << " tentativas." << std::endl;
    } else {
        std::cout << "Suas tentativas acabaram. Voce usou todas as " << limiteTentativas << " tentativas." << std::endl;
    }
    
    return 0;
}
