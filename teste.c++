#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

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

    // Defina as perguntas e respostas aqui...

    // Resto do código...

    // Definindo as cores ANSI
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";
    const std::string PURPLE = "\033[0;35m";
    const std::string GREEN = "\033[32m";
    const std::string CYAN = "\033[1;36m";

    std::random_shuffle(questions.begin(), questions.end());

    std::cout << BOLD << PURPLE << "Bem-vindo ao Jogo de Perguntas e Respostas!" << RESET << std::endl;
    std::cout << BOLD << "Por favor, insira o nome da sua equipe: " << RESET;
    std::string teamName;
    std::cin >> teamName;

    int totalRounds = 1;
    int totalQuestionsPerRound = 12;
    int teamScore = 0;
    int correctAnswers = 0;
    int wrongAnswers = 0;

    for (int round = 1; round <= totalRounds; ++round) {
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << BOLD << "Rodada " << round << " de " << totalRounds << RESET << std::endl;

        for (int questionIndex = 0; questionIndex < totalQuestionsPerRound; ++questionIndex) {
            std::cout << "-----------------------------------------" << std::endl;
            std::cout << BOLD << "Pergunta " << questionIndex + 1 << " de " << totalQuestionsPerRound << RESET << std::endl;
            displayQuestion(questions[questionIndex]);
            
            int playerAnswer;
            std::cout << "Insira o numero da opcao correta: ";
            std::cin >> playerAnswer;

            if (playerAnswer >= 1 && playerAnswer <= static_cast<int>(questions[questionIndex].options.size())) {
                if (checkAnswer(playerAnswer, questions[questionIndex])) {
                    std::cout << BOLD << GREEN << "Resposta correta!" << RESET << std::endl;
                    teamScore++;
                    correctAnswers++;
                } else {
                    std::cout << BOLD << PURPLE << "Resposta incorreta." << RESET << std::endl;
                    wrongAnswers++;
                }
            } else {
                std::cout << BOLD << "Opcao invalida! Nenhum ponto adicionado." << RESET << std::endl;
            }
        }

        std::cout << "-----------------------------------------" << std::endl;
        std::cout << BOLD << "Pontuacao da equipe " << teamName << " após a rodada " << round << ": " << teamScore << " pontos." << RESET << std::endl;
    }

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << BOLD << "Fim do jogo! Pontuacao final da equipe " << teamName << ": " << teamScore << " pontos." << RESET << std::endl;
    std::cout << BOLD << "Total de acertos: " << correctAnswers << RESET << std::endl;
    std::cout << BOLD << "Total de erros: " << wrongAnswers << RESET << std::endl;

    return 0;
}