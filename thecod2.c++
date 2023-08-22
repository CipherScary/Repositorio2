#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>

struct Question {
    std::string question;
    std::vector<std::string> options;
    int correctOption;
};

void displayQuestion(const Question& q) {
    std::cout << q.question << std::endl;
    for (size_t i = 0; i < q.options.size(); ++i) {
        std::cout << i + 1 << ". " << q.options[i] << std::endl;
    }
}

bool checkAnswer(int playerAnswer, const Question& q) {
    return playerAnswer == q.correctOption;
}

int main() {
    std::srand(std::time(nullptr));
    std::vector<Question> questions;

    // Perguntas fáceis
    Question q1;
    q1.question = "Qual é a capital do Brasil?";
    q1.options = {"São Paulo", "Brasília", "Rio de Janeiro", "Belo Horizonte"};
    q1.correctOption = 2;
    questions.push_back(q1);

    Question q2;
    q2.question = "Qual é a cor do céu em um dia ensolarado?";
    q2.options = {"Verde", "Azul", "Vermelho", "Amarelo"};
    q2.correctOption = 2;
    questions.push_back(q2);

    Question q3;
    q3.question = "Quantos continentes existem?";
    q3.options = {"3", "5", "7", "6"};
    q3.correctOption = 3;
    questions.push_back(q3);

    Question q4;
    q4.question = "Qual é o maior planeta do Sistema Solar?";
    q4.options = {"Terra", "Marte", "Júpiter", "Vênus"};
    q4.correctOption = 3;
    questions.push_back(q4);

    Question q5;
    q5.question = "Quantos anos tem um século?";
    q5.options = {"10", "100", "1000", "50"};
    q5.correctOption = 2;
    questions.push_back(q5);

    Question q6;
    q6.question = "Qual é o animal considerado 'o melhor amigo do homem'?";
    q6.options = {"Gato", "Cachorro", "Coelho", "Girafa"};
    q6.correctOption = 2;
    questions.push_back(q6);

    // Perguntas difíceis
    Question q7;
    q7.question = "Em qual ano ocorreu a Revolução Francesa?";
    q7.options = {"1789", "1820", "1850", "1910"};
    q7.correctOption = 1;
    questions.push_back(q7);

    Question q8;
    q8.question = "Qual é o elemento químico com o símbolo 'Fe'?";
    q8.options = {"Ferro", "Fósforo", "Flúor", "Francium"};
    q8.correctOption = 1;
    questions.push_back(q8);

    Question q9;
    q9.question = "Quem escreveu o livro 'Dom Quixote'?";
    q9.options = {"William Shakespeare", "Miguel de Cervantes", "Charles Dickens", "Friedrich Nietzsche"};
    q9.correctOption = 2;
    questions.push_back(q9);

    Question q10;
    q10.question = "Qual é o valor de π (pi)?";
    q10.options = {"3.14", "2.71", "1.62", "4.20"};
    q10.correctOption = 1;
    questions.push_back(q10);

    Question q11;
    q11.question = "Qual é o maior deserto do mundo?";
    q11.options = {"Deserto de Mojave", "Deserto de Kalahari", "Deserto de Atacama", "Deserto do Saara"};
    q11.correctOption = 4;
    questions.push_back(q11);

    Question q12;
    q12.question = "Qual é a pintura mais famosa de Leonardo da Vinci?";
    q12.options = {"A Última Ceia", "Mona Lisa", "A Noite Estrelada", "Guernica"};
    q12.correctOption = 2;
    questions.push_back(q12);

    std::random_shuffle(questions.begin(), questions.end());

    std::cout << "Bem-vindo ao Jogo de Perguntas e Respostas!" << std::endl;
    std::cout << "Quantas equipes vão jogar? (1 a 3): ";
    int numTeams;
    std::cin >> numTeams;

    if (numTeams < 1 || numTeams > 3) {
        std::cout << "Número inválido de equipes. O programa será encerrado." << std::endl;
        return 1;
    }

    std::vector<std::string> teamNames(numTeams);
    std::vector<int> teamScores(numTeams, 0);

    for (int teamIndex = 0; teamIndex < numTeams; ++teamIndex) {
        std::cout << "Insira o nome da equipe " << teamIndex + 1 << ": ";
        std::cin >> teamNames[teamIndex];

        int totalRounds = 1;
        int totalQuestionsPerRound = 12;
        int correctAnswers = 0;

        for (int round = 1; round <= totalRounds; ++round) {
            std::cout << "-----------------------------------------" << std::endl;
            std::cout << "Rodada " << round << " da equipe " << teamNames[teamIndex] << std::endl;

            for (int questionIndex = 0; questionIndex < totalQuestionsPerRound; ++questionIndex) {
                std::cout << "-----------------------------------------" << std::endl;
                std::cout << "Pergunta " << questionIndex + 1 << " de " << totalQuestionsPerRound << std::endl;
                displayQuestion(questions[questionIndex]);

                int playerAnswer;

                // Obter a resposta do jogador e garantir que seja válida (1 a 4)
                do {
                    std::cout << "Escolha a opção (1 a 4): ";
                    std::cin >> playerAnswer;

                    if (std::cin.fail() || playerAnswer < 1 || playerAnswer > 4) {
                        std::cout << "Opção inválida. Escolha a opção (1 a 4): ";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else {
                        break; // Sai do loop quando a entrada é válida
                    }
                } while (true);

                if (checkAnswer(playerAnswer, questions[questionIndex])) {
                    std::cout << "Resposta correta! Pontos adicionados." << std::endl;
                    teamScores[teamIndex]++;
                    correctAnswers++;
                } else {
                    std::cout << "Resposta incorreta." << std::endl;
                }
            }

            std::cout << "-----------------------------------------" << std::endl;
            std::cout << "Pontuação da equipe " << teamNames[teamIndex] << " após a rodada " << round << ": " << teamScores[teamIndex] << " pontos." << std::endl;
        }
    }

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Fim do jogo!" << std::endl;

    for (int teamIndex = 0; teamIndex < numTeams; ++teamIndex) {
        std::cout << "Pontuação final da equipe " << teamNames[teamIndex] << ": " << teamScores[teamIndex] << " pontos." << std::endl;
    }

    return 0;
}