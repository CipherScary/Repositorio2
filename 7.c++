#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Função para gerar uma letra aleatória entre 'A' e 'Z'
char geraletraAleatoria() {
    return 'A' + rand() % 26;
}

int main() {
    srand(time(0));  // Inicialização da semente para geração de números aleatórios

    char letraSorteada;
    int tentativas;
    char chute;
    char jogarNovamente;

    do {
        letraSorteada = geraletraAleatoria();  // Gera uma nova letra aleatória
        tentativas = 5;  // Define o número de tentativas para 5

        cout << "Adivinhe a letra sorteada!" << endl;

        // Verifica se a letra sorteada é uma vogal ou consoante
        if (letraSorteada == 'A' || letraSorteada == 'E' || letraSorteada == 'I' || letraSorteada == 'O' || letraSorteada == 'U' ||
            letraSorteada == 'a' || letraSorteada == 'e' || letraSorteada == 'i' || letraSorteada == 'o' || letraSorteada == 'u') {
            cout << "Dica: A letra sorteada é uma vogal." << endl;
        } else {
            cout << "Dica: A letra sorteada é uma consoante." << endl;
        }

        while (tentativas > 0) {
            cout << "Digite uma letra entre A e Z: ";
            cin >> chute;

            if (chute >= 'A' && chute <= 'Z') {
                if (chute == letraSorteada) {
                    cout << "Parabéns você acertou!" << endl;
                    break;  // Sai do loop se o jogador acertar a letra
                } else {
                    cout << "Você errou!" << endl;
                    tentativas--;
                    cout << "Tentativas restantes: " << tentativas << endl;
                }
            } else {
                cout << "Por favor, digite uma letra válida entre A e Z." << endl;
            }
        }

        if (tentativas == 0) {
            cout << "Suas tentativas se esgotaram. A letra sorteada era: " << letraSorteada << endl;
        }

        cout << "Deseja jogar novamente? (S/N): ";
        cin >> jogarNovamente;

    } while (jogarNovamente == 'S' || jogarNovamente == 's');  // Repete o jogo se o jogador quiser

    cout << "Obrigado por jogar!" << endl;
    return 0;
}
