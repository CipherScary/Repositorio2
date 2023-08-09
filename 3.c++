#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Função para gerar uma letra aleatória entre 'A' e 'Z'
char geraletraAleatoria() {
    return 'A' + rand() % 26; // Gera um número aleatório entre 0 e 25 e soma com 'A' para obter uma letra aleatória
}

int main() {
    srand(time(0)); // Inicializa o gerador de números aleatórios com o valor do tempo atual

    char letraSorteada = geraletraAleatoria(); // Gera uma letra aleatória
    int tentativas = 5; // Define o número de tentativas
    char chute;

    cout << "Adivinhe a letra sorteada!" << endl;

    while (tentativas > 0) {
        cout << "Digite uma letra: ";
        cin >> chute;
    
        if (chute == letraSorteada) {
            cout << "Parabens você conseguiu!" << endl;
            return 0;
        } else {
            cout << "Você errou!" << endl;
            tentativas--;
            cout << "Tentativas restantes: " << tentativas << endl;
        }
    }
    
    cout << "Suas tentativas se esgotaram. A letra sorteada era: " << letraSorteada << endl;
    return 0;
}
