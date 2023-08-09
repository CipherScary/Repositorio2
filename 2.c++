#include <iostream>
#include <cctype> // Incluindo a biblioteca que contém a função isalpha
using namespace std;

// Função para verificar se um caractere é uma letra do alfabeto
bool verificarLetraNoAlfabeto(char letra) {
    return isalpha(letra); // A função isalpha verifica se o caractere é uma letra
}

int main() {
    char letraDigitada;

    cout << "Digite uma letra:"; 
    cin >> letraDigitada; 

    // Loop para verificar se a letra digitada está no alfabeto
    while (!verificarLetraNoAlfabeto(letraDigitada)) {
        cout << "A letra digitada não faz parte do alfabeto. Tente novamente: ";
        cin >> letraDigitada;
    }

    cout << "A letra existe no alfabeto." << endl;

    return 0;
}
