#include <iostream>
#include <random>
#include <ctime>

int gerarNumeroAleatorio() {
    // Definir o intervalo para os números aleatórios desejados
    int min = 1;
    int max = 60; // Você pode ajustar esse valor conforme necessário
   
    // Gerar um número aleatório no intervalo especificado
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    // Sortear um número aleatório
    int numeroSorteado = gerarNumeroAleatorio();
   
    // Permitir que o jogador chute o número até acertar ou atingir o limite de tentativas
    int tentativas = 0;
    int numeroChute;
    do {
        std::cout << "Tentativa " << tentativas + 1 << ": Digite um número: ";
        std::cin >> numeroChute;
       
        if (numeroChute == numeroSorteado) {
            std::cout << "Parabéns! Você acertou o número sorteado!" << std::endl;
            break;
        } else {
            std::cout << "Número incorreto. Tente novamente." << std::endl;
        }
       
        tentativas++;
    } while (tentativas < 5);
   
    // Informar o número sorteado
    std::cout << "O número sorteado era: " << numeroSorteado << std::endl;
    std::cout << "Você utilizou " << tentativas + 1 << " tentativas." << std::endl;
   
    return 0;
}