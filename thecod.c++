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

    // Perguntas de nível médio
    Question q1;
    q1.question = "Qual e o operador de atribuicao em C++?";
    q1.options = {"=", "==", ":", "->"};
    q1.correctOption = 1;
    questions.push_back(q1);

    Question q2;
    q2.question = "Qual e o maior planeta do Sistema Solar?";
    q2.options = {"Terra", "Marte", "Jupiter", "Venus"};
    q2.correctOption = 3;
    questions.push_back(q2);

    Question q3;
    q3.question = "Qual e o elemento quimico mais abundante na crosta terrestre?";
    q3.options = {"Oxigenio", "Silicio", "Ferro", "Aluminio"};
    q3.correctOption = 2;
    questions.push_back(q3);

    Question q4;
    q4.question = "Quem escreveu a peça de teatro 'Romeu e Julieta'?";
    q4.options = {"William Shakespeare", "Jane Austen", "Charles Dickens", "Mark Twain"};
    q4.correctOption = 1;
    questions.push_back(q4);

    Question q5;
    q5.question = "Qual e o maior oceano do mundo?";
    q5.options = {"Oceano Atlantico", "Oceano indico", "Oceano artico", "Oceano Pacifico"};
    q5.correctOption = 4;
    questions.push_back(q5);

    Question q6;
    q6.question = "Qual e o simbolo quimico do ouro?";
    q6.options = {"Au", "Ag", "Cu", "Fe"};
    q6.correctOption = 1;
    questions.push_back(q6);

    // Perguntas de nível difícil
    Question q7;
    q7.question = "Qual e o processo pelo qual as plantas fabricam seu proprio alimento?";
    q7.options = {"Fotossintese", "Respiracao", "Digestao", "Evaporacao"};
    q7.correctOption = 1;
    questions.push_back(q7);

    Question q8;
    q8.question = "Quantos planetas fazem parte do Sistema Solar?";
    q8.options = {"7", "8", "9", "10"};
    q8.correctOption = 2;
    questions.push_back(q8);

    Question q9;
    q9.question = "Qual e a capital do Japao?";
    q9.options = {"Pequim", "Seul", "Toquio", "Bangcoc"};
    q9.correctOption = 3;
    questions.push_back(q9);

    Question q10;
    q10.question = "Qual e a maior montanha do mundo?";
    q10.options = {"Monte Everest", "Monte Kilimanjaro", "Monte McKinley", "Monte Fuji"};
    q10.correctOption = 1;
    questions.push_back(q10);

    Question q11;
    q11.question = "Qual e o maior animal terrestre?";
    q11.options = {"Elefante", "Girafa", "Rinoceronte", "Leao"};
    q11.correctOption = 1;
    questions.push_back(q11);

    Question q12;
    q12.question = "Qual e a moeda oficial do Brasil?";
    q12.options = {"Peso", "Dolar", "Euro", "Real"};
    q12.correctOption = 4;
    questions.push_back(q12);

    std::random_shuffle(questions.begin(), questions.end());

    std::cout << "Bem-vindo ao Jogo de Perguntas e Respostas!" << std::endl;
    std::cout << "Por favor, insira o nome da sua equipe: ";
    std::string teamName;
    std::cin >> teamName;

    int totalRounds = 1;
    int totalQuestionsPerRound = 12;
    int teamScore = 0;
    int correctAnswers = 0;
    int wrongAnswers = 0;

    for (int round = 1; round <= totalRounds; ++round) {
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "Rodada " << round << " de " << totalRounds << std::endl;

        for (int questionIndex = 0; questionIndex < totalQuestionsPerRound; ++questionIndex) {
            std::cout << "-----------------------------------------" << std::endl;
            std::cout << "Pergunta " << questionIndex + 1 << " de " << totalQuestionsPerRound << std::endl;
            displayQuestion(questions[questionIndex]);

            int playerAnswer;
            
            // Obter a resposta do jogador e garantir que seja válida (1 a 4)
            do {
                std::cout << "Escolha a opçao (1 a 4): ";
                std::cin >> playerAnswer;

                if (std::cin.fail() || playerAnswer < 1 || playerAnswer > 4) {
                    std::cout << "Opção invalida. Escolha a opcao (1 a 4): ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    break; // Sai do loop quando a entrada é válida
                }
            } while (true);

            if (checkAnswer(playerAnswer, questions[questionIndex])) {
                std::cout << "Resposta correta! Pontos adicionados." << std::endl;
                teamScore++;
                correctAnswers++;
            } else {
                std::cout << "Resposta incorreta." << std::endl;
                wrongAnswers++;
            }
        }

        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "Pontuacao da equipe " << teamName << " apos a rodada " << round << ": " << teamScore << " pontos." << std::endl;
    }

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Fim do jogo! Pontuacao final da equipe " << teamName << ": " << teamScore << " pontos." << std::endl;
    std::cout << "Total de acertos: " << correctAnswers << std::endl;
    std::cout << "Total de erros: " << wrongAnswers << std::endl;

    return 0;
}