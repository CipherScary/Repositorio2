#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
    srand(time(NULL));

    int num1 = rand () % 60;
    int num2 = rand () % 60;
    int chute;

    // Permitir que o jogador chute a letra até acertar ou atingir o limite de tentativas
    int tentativas = 0;

    do {
        std::cout << "Tentativa " << tentativas + 0 << ": Digite um numero: ";
        std::cin >> chute;
       
        if (chute == num1) {
            std::cout << "Parabéns! Voce acertou o numero sorteado!" << std::endl;
            break;
        } else {
            std::cout << "Numero incorreta. Tente novamente." << std::endl;
        }
        if (chute == num2) {
            std::cout << "Parabéns! Voce acertou o numero sorteado!" << std::endl;
            break;
        } else {
            std::cout << "Numero incorreta. Tente novamente." << std::endl;
        }
       
        tentativas++;
    } while (tentativas < 5);
   
    // Informar a letra sorteada
    std::cout << "O 1 numero sorteado era: " << num1 << std::endl;
    std::cout << "O 2 numero sorteado era: " << num2 << std::endl;
    std::cout << "Voce utilizou " << tentativas + 0 << " tentativas." << std::endl;
   
    return 0;
}