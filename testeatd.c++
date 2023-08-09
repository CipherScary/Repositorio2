#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Função para solicitar ao jogador que escolha 6 números distintos entre 1 e 60.
vector<int> escolherNumeros() {
    vector<int> numerosEscolhidos;
    
    cout << "Escolha 6 números distintos entre 1 e 60:" << endl;
    
    for (int i = 0; i < 6; i++) {
        int numero;
        cin >> numero;
        
        // Verifica se o número já foi escolhido anteriormente
        if (find(numerosEscolhidos.begin(), numerosEscolhidos.end(), numero) != numerosEscolhidos.end()) {
            cout << "Número repetido. Escolha outro número." << endl;
            i--;
            continue;
        }
        
        numerosEscolhidos.push_back(numero);
    }
    
    return numerosEscolhidos;
}

// Função para realizar o sorteio de 6 números aleatórios distintos entre 1 e 60.
vector<int> sortearNumeros() {
    vector<int> numerosSorteados;
    
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios
    
    while (numerosSorteados.size() < 6) {
        int numero = rand() % 60 + 1;
        
        // Verifica se o número já foi sorteado anteriormente
        if (find(numerosSorteados.begin(), numerosSorteados.end(), numero) != numerosSorteados.end()) {
            continue;
        }
        
        numerosSorteados.push_back(numero);
    }
    
    return numerosSorteados;
}

// Função para comparar a combinação sorteada com os números escolhidos pelo jogador e informar a quantidade de acertos.
int verificarAcertos(const vector<int>& numerosEscolhidos, const vector<int>& numerosSorteados) {
    int acertos = 0;
    
    for (int numero : numerosEscolhidos) {
        if (find(numerosSorteados.begin(), numerosSorteados.end(), numero) != numerosSorteados.end()) {
            acertos++;
        }
    }
    
    return acertos;
}

int main() {
    bool sair = false;
    
    while (!sair) {
        vector<int> numerosEscolhidos = escolherNumeros();
        vector<int> numerosSorteados = sortearNumeros();
        
        int acertos = verificarAcertos(numerosEscolhidos, numerosSorteados);
        
        cout << "Números sorteados: ";
        for (int numero : numerosSorteados) {
            cout << numero << " ";
        }
        cout << endl;
        
        if (acertos == 6) {
            cout << "Parabéns! Você acertou todos os números." << endl;
            cout << "Foram necessários " << numerosSorteados.size() << " sorteios para acertar." << endl;
        } else {
            cout << "Você acertou " << acertos << " números." << endl;
            cout << "Tente novamente." << endl;
        }
        
        cout << "Deseja jogar novamente? (S/N) ";
        char opcao;
        cin >> opcao;
        
        if (opcao == 'N' || opcao == 'n') {
            sair = true;
        }
    }
    
    cout << "Obrigado por jogar!" << endl;
    
    return 0;
}