#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

bool Existe(int valores[], int tam, int valor) {
    for (int i = 0; i < tam; i++)
    {
        if (valores[i] == valor)
            return true;     
    }
    return false;
}

void GeraALeatorio(int numeros[], int quantNumeros, int Limite) {
    srand(time(NULL));


    int v;
    for (int i = 0; i < quantNumeros; i++)
    {
        numeros[i] = rand() % Limite;  
    }
    

}

int main (){
    int numeros [60];
    GeraALeatorio(numeros,0,60);