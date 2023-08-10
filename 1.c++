#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ctime>
using namespace std;

int main () {

    srand(time(NULL));

    int num1 = rand () % 60;
    int num2 = rand () % 60;
    int num3 = rand () % 60;
    int num4 = rand () % 60;
    int num5 = rand () % 60;
    int num6 = rand () % 60;
    int chute 

    while (true) {
        cout << "Acerte o primeiro número de 0 a 60: ";
        cin >> chute;

        if (chute > num1)
        
            cout << "Voce errou" << endl;
         else if (chute < num1)
            cout << "Voce errou" << endl;
        else { 
            cout << "Voce ganhou" << endl;
            break;
       }
    }
    

    return 0;
}