#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char geraletraAleatoria() {
    return 'A' + rand() %26; // Gerador de letra aleatoria 
}

int main() {
    srand(time(0));
    // Sistema de tentativas e letra aleatoria
    char letraSorteada = geraletraAleatoria(); 
    int tentativas = 5;
    char chute;

    cout << "Adivinhe a letra sorteada!" << endl;

    while (tentativas > 0) {
        cout << "Digite uma letra: "; 
        cin >> chute;
    
    
    if (chute == letraSorteada) {
        cout << "Parabens você conseguiu!" << endl; // Informa se o usuario acertou
        return 0;
    } else {
        cout << "Você errou!" << endl; // Informa se o usuario errou
        tentativas--;
        cout << "Tentativas restantes: " << tentativas << endl; // Quantidade de tentativas restantes
        }
    }
    
    cout << "Suas tentativas se esgotaram. A letra sorteada era: " << letraSorteada << endl; // Informa ao usuario q as tentativas se egotaram e qual era letra sorteada
    return 0;
}