#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definição das estruturas de dados
struct Question
{
    string text;
    vector<string> options;
    char correctOption;
};

struct Group
{
    string name;
    vector<Question> questions;
};

// Função para apresentar uma pergunta e obter a resposta do usuário
char askQuestion(const Question &question)
{
    cout << question.text << endl;
    for (size_t i = 0; i < question.options.size(); ++i)
    {
        cout << static_cast<char>('a' + i) << ") " << question.options[i] << endl;
    }
    char answer;
    cout << "Resposta: ";
    cin >> answer;
    return answer;
}

// Função principal para executar o quiz
void runQuiz(Group &group, int &pontuacao)
{
    int score = 0;
    for (const Question &question : group.questions)
    {
        char userAnswer = askQuestion(question);
        if (userAnswer == question.correctOption)
        {
            cout << "Você acertou!" << endl;
            ++score;
        }
        else
        {
            cout << "Você errou." << endl;
        }
    }
    cout << "Pontuação do grupo " << group.name << ": " << score << " / " << group.questions.size() << endl;
    pontuacao = score;
}
int main()
{
    // Definição dos grupos e perguntas
    Group grupo1{"Grupo 1",
                 {{"Qual é a função em C++ utilizada para ler um valor inteiro do teclado?", {"a) read()", "b) scan()", "c) get()", "d) cin >>"}, 'd'},
                  {"Qual é o tipo de dado utilizado para representar valores booleanos (verdadeiro/falso) em C++?", {"a) bool", "b) boolean", "c) bit", "d) truefalse"}, 'a'},
                  {"Qual é a declaração correta de uma variável inteira em C++?", {"a) integer x;", "b) int x;", "c) var x;", "d) x = int;"}, 'b'},
                  {"Como se acessa o terceiro elemento de um vetor chamado 'nums'?", {"a) nums[2];", "b) nums[3];", "c) nums[1];", "d) nums(3);"}, 'a'}}};

    Group grupo2{"Grupo 2",
                 {{"Qual é a forma correta de calcular o tamanho de um vetor chamado 'arr'?", {"a) size(arr);", "b) length(arr);", "c) arr.size();", "d) arr.length();"}, 'c'},
                  {"Qual é a forma correta de declarar uma constante em C++?", {"a) const x;", "b) constant int x;", "c) const int x;", "d) int constant x;"}, 'c'},
                  {"Qual é o tipo de dado utilizado para representar números em ponto flutuante de dupla precisão em C++?", {"a) float", "b) double", "c) long", "d) decimal"}, 'b'},
                  {"Como você lê uma string com espaços em C++ usando a função 'cin'?", {"a) cin.read()", "b) cin.getline()", "c) cin.str()", "d) cin.string()"}, 'b'}}};

    Group grupo4{"Grupo 4",
                 {{"Qual é a sintaxe correta para declarar um vetor de inteiros em C++?", {"a) vetor<int> v;", "b) int[] v;", "c) vetor<int> v[];", "d) int v[];"}, 'b'},
                  {"O que acontece quando duas variáveis do mesmo tipo são declaradas com o mesmo nome em C++?", {"a) O compilador gera um erro.", "b) A variável é automaticamente inicializada com zero.", "c) A variável que foi declarada por último prevalece.", "d) O programa entra em um loop infinito."}, 'a'},
                  {"Qual é o tipo de dado utilizado para representar números inteiros em C++?", {"a) inteiros", "b) char", "c) double", "d) int"}, 'd'},
                  {"Para ler um número em ponto flutuante em C++, qual é o operador adequado?", {"a) read()", "b) get()", "c) cin >>", "d) float()"}, 'c'}}};

    // Variáveis para armazenar as pontuações dos grupos
    int pontuacaoGrupo1 = 0;
    int pontuacaoGrupo2 = 0;
    int pontuacaoGrupo4 = 0;

    // Menu de opções
    int choice;
    do
    {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Grupo 1" << endl;
        cout << "2. Grupo 2" << endl;
        cout << "3. Grupo 4" << endl;
        cout << "4. Ver pontuação" << endl;
        cout << "0. Sair" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            runQuiz(grupo1, pontuacaoGrupo1);
            break;
        case 2:
            runQuiz(grupo2, pontuacaoGrupo2);
            break;
        case 3:
            runQuiz(grupo4, pontuacaoGrupo4);
            break;
        case 4:
            cout << "Pontuação do Grupo 1: " << pontuacaoGrupo1 << endl;
            cout << "Pontuação do Grupo 2: " << pontuacaoGrupo2 << endl;
            cout << "Pontuação do Grupo 4: " << pontuacaoGrupo4 << endl;
            break;
        case 0:
            cout << "Saindo do programa." << endl;
            break;
        default:
            cout << "Opção inválida." << endl;
        }
    } while (choice != 9);

    return 0;
}