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
   

    while (true) {
        cout << "Digite o pimeiro numero: ";
        cin >> tentativa;

        if (tentativa > num1)
            cout << "O numero é menor" << endl;
         
         else if (tentativa < num1)
             cout << "O numero é maoir" << endl;
        
         else { 
            cout << "Voce acertou o primeiro numero" << endl;
            break;
       }
    }
    while (true) {
        cout << "Digite o segundo numero: ";
        cin >> tentativa2;

        if (tentativa > num2)
            cout << "O numero é menor" << endl;
         
         else if (tentativa2 < num2)
             cout << "O numero é maoir" << endl;
        
         else { 
            cout << "Voce acertou o segundo numero" << endl;
            break;
       }
    }


    return 0;
}