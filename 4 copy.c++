#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

int main (){

    srand(time(NULL));

    int num1 = rand() %  60;
    int num2 = rand() %  60;
    int tentativa;
    int tentativa2;
    int acertos = 0;
    int erros = 0;
   
   char opcao;
    do {
        // Sortear uma letra aleatória
        char num1 = rand() % 60;
       
        // Permitir que o jogador chute a letra até acertar ou atingir o limite de tentativas
        int tentativas = 0;
        char tentativa;
        do {
            std::cout << "Tentativa " << tentativas + 1 << ": Digite um numero: ";
            std::cin >> tentativa;
           
            if (tentativa == num1) {
                std::cout << "Parabéns! Voce acertou o numero sorteado!" << std::endl;
                acertos++;
                break;
            } else {
                std::cout << "Numero incorreto. Tente novamente." << std::endl;
                erros++;
            }
           
            tentativas++;
        } while (tentativas < 5);
  
        // Informar a letra sorteada
        std::cout << "O numero sorteado era: " << num1 << std::endl;
       
        // Perguntar ao jogador se ele deseja jogar novamente
        std::cout << "Deseja jogar novamente? (S/N): ";
        std::cin >> opcao;
    } while (opcao == 'S' || opcao == 's');
    
    return 0;
}