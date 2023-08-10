#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

int main (){

    srand(time(NULL));

    int num1 = rand() %  60;
    int tentativa;

   

    while (true) {
        cout << "Digite o pimeiro numero: ";
        cin >> tentativa;

        if (tentativa > num1)
            cout << "O numero é menor" << endl;
         
         else if (tentativa < num1)
             cout << "O numero é maoir" << endl;
        
         else { 
            cout << "Voce ganhou" << endl;
            break;
       }
    }



    return 0;
}