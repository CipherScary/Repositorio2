#include <iostream>
#include <random>
#include <ctime>

char gerarLetraAleatoria() {
    // Vetor com as letras do alfabeto
    char alfabeto[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23', '24', '25', '26', '27', '28', '29', '30', '31', '32', '33', '34', '35', '36', '37', '38', '39', '40', '41', '42', '43', '44', '45', '46', '47', '48', '49', '50', '51', '52', '53', '54', '55', '56', '57', '58', '59', '60'};
   
    // Obter um índice aleatório
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 60);
    int indice = dis(gen);
   
    // Retornar a letra correspondente ao índice
    return alfabeto[indice];
}

int main() {
    int acertos = 0;
    int erros = 0;
   
    char opcao;
    do {
        // Sortear uma letra aleatória
        char letraSorteada = gerarLetraAleatoria();
       
        // Permitir que o jogador chute a letra até acertar ou atingir o limite de tentativas
        int tentativas = 0;
        char letraChute;
        do {
            std::cout << "Tentativa " << tentativas + 1 << ": Digite uma letra: ";
            std::cin >> letraChute;
           
            if (letraChute == letraSorteada) {
                std::cout << "Parabéns! Voce acertou a letra sorteada!" << std::endl;
                acertos++;
                break;
            } else {
                std::cout << "Letra incorreta. Tente novamente." << std::endl;
                erros++;
            }
           
            tentativas++;
        } while (tentativas < 5);
       
        // Informar a letra sorteada
        std::cout << "A letra sorteada era: " << letraSorteada << std::endl;
       
        // Perguntar ao jogador se ele deseja jogar novamente
        std::cout << "Deseja jogar novamente? (S/N): ";
        std::cin >> opcao;
    } while (opcao == 'S' || opcao == 's');
   
    std::cout << "Acertos: " << acertos << std::endl;
    std::cout << "Erros: " << erros << std::endl;
    std::cout << "Obrigado por jogar! Ate a proxima!" << std::endl;
   
    return 0;
}