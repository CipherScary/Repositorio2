#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
// Sistema de tentativas e letra aleatoria
char geraletraAleatoria() {
    return 'A' + rand() %26;
}

int main() {
    //Inicializador de numeros aleatorios com o tempo atual
    srand(time(0));

    char letraAleatoria = geraletraAleatoria();
    cout << "Letra aleatoria gerada: " << letraAleatoria << endl;

    return 0;
}