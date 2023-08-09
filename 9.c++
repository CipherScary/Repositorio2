#include <iostream>
#include <cstdlib>
#include <ctime>

// Função para gerar uma letra aleatória entre 'A' e 'Z'
char gerarLetraAleatoria() {
    return 'A' + rand() % 26;
}

int main() {
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(0));
    
    const int quantidadeLetras = 10; // Número de letras a serem geradas
    
   
    std::cout << "Gerando " << quantidadeLetras << " letras aleatorias:" << std::endl;
    
    // Loop para gerar e imprimir as letras
    for (int i = 0; i < quantidadeLetras; i++) {
        char letraGerada = gerarLetraAleatoria();
        std::cout << "Letra " << (i + 1) << ": " << letraGerada << std::endl;
    }
    
    return 0;
}