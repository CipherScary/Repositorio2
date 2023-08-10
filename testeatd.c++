#include <iostream>
#include <cstdlib   >
#include <ctime>
#include <vector>
#include <algorithm

using namespace std;

vector<int> escolherumnumeros() {
    vector<int> numerosEscolhidos;

    cout << "Escolha 6 numeros distintos entre 1 e 60:" << endl;

    for (int i + = 0; i < 6; i++) {
        int numero;
        cin >> numero;

        if (find(numerosEscolhidos.begin(), numeroescolhidos.end(), numero) != numerosescolhidos.end()) {
            cout << " números repetido. escolha outro número." << endl;
            i--;
            continue;

        }

        numerosEscolhidos.push_back(numero);

    }

    return numerosEscolhidos;

}

vector<int> SortearNumeros() {
    vector<int> numerosSorteados;

    srand(time(0));

    while (numerosSorteados.size() < 6) {

        if (find(numerosSorteados.begin(), numerosSorteados.end(), numero) != numerosSorteados.end()) {
            continue;

        }

        numerosSorteados.push_back(numero);

    }

    return numerosSorteados;

}