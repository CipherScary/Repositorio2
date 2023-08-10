#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
    srand(time(NULL));

    int num1 = rand () % 60;
    int chute;

    // Permitir que o jogador chute a letra até acertar ou atingir o limite de tentativas
    int tentativas = 0;

    do {
        std::cout << "Tentativa " << tentativas + 1 << ": Digite um numero: ";
        std::cin >> chute;
       
        if (chute == num1) {
            std::cout << "Parabéns! Voce acertou o numero sorteado!" << std::endl;
            break;
        } else {
            std::cout << "Numero incorreta. Tente novamente." << std::endl;
        }
       
        tentativas++;
    } while (tentativas < 5);
   
    // Informar a letra sorteada
    std::cout << "O numero sorteado era: " << num1 << std::endl;
    std::cout << "Voce utilizou " << tentativas + 0 << " tentativas." << std::endl;
   
    return 0;
}