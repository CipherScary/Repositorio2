#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Função para obter um número inteiro aleatório entre min e max (inclusivos)
int obterAtributoAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Função para calcular o modificador para atributos e nível em D&D 5e
int calcularModificador(int valor) {
    return (valor - 10) / 2;
}

// Função para imprimir o atributo e seu modificador
void imprimirAtributoModificador(const std::string& atributo, int valor) {
    int modificador = calcularModificador(valor);
    std::cout << atributo << ": " << valor << " (modificador: " << modificador << ")" << std::endl;
}

// Função para obter o valor de um atributo entre min e max (inclusivos)
int selecaoDeNivel(const std::string& atributo, int min, int max) {
    int valor;
    while (true) {
        std::cout << "Digite o valor do atributo " << atributo << " entre " << min << " e " << max << ": ";
        std::cin >> valor;

        if (std::cin.fail() || valor < min || valor > max) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Valor inválido. Tente novamente." << std::endl;
        } else {
            std::cin.ignore(10000, '\n');
            return valor;
        }
    }
}

int main() {
    std::cout << "=== Ficha de RPG (D&D 5e) ===" << std::endl;

    // Variáveis para os atributos e nível
    int forca, destreza, constituicao, inteligencia, sabedoria, carisma, nivel;

    // Variáveis para o nome, raça e classe do personagem
    std::string nome, raca, classe;

    // Variáveis para a personalização do personagem
    int idade;
    std::string idiomas;
    double altura;

    // Variáveis para equipamento e inventário
    std::string armaEquipada, itemInventario;

    // Solicitar ao usuário para inserir o nome, raça, classe e personalização
    std::cout << "Digite o nome do personagem: ";
    std::getline(std::cin, nome);

    std::cout << "Digite a raça do personagem: ";
    std::getline(std::cin, raca);

    std::cout << "Digite a classe do personagem: ";
    std::getline(std::cin, classe);

    std::cout << "Digite a idade do personagem: ";
    std::cin >> idade;

    std::cin.ignore(10000, '\n'); // Limpar o buffer de entrada após ler um inteiro

    std::cout << "Digite os idiomas que o personagem conhece: ";
    std::getline(std::cin, idiomas);

    std::cout << "Digite a altura do personagem (em metros): ";
    std::cin >> altura;

    // Inicializar a semente para a função rand() usando o tempo atual
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Solicitar ao usuário para escolher o nível do personagem
    nivel = selecaoDeNivel("nível", 1, 20);

    // Solicitar ao usuário para escolher os atributos (entre 10 e 30)
    std::cout << "\nAtributos: " << std::endl;
    forca = obterAtributoAleatorio(10, 30);
    destreza = obterAtributoAleatorio(10, 30);
    constituicao = obterAtributoAleatorio(10, 30);
    inteligencia = obterAtributoAleatorio(10, 30);
    sabedoria = obterAtributoAleatorio(10, 30);
    carisma = obterAtributoAleatorio(10, 30);

    // Exibir os atributos, modificadores, nome, raça, classe, nível e personalização do personagem
    std::cout << "\n=== Ficha do Personagem ===" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Raça: " << raca << std::endl;
    std::cout << "Classe: " << classe << std::endl;
    std::cout << "Idade: " << idade << " anos" << std::endl;
    std::cout << "Idiomas: " << idiomas << std::endl;
    std::cout << "Altura: " << altura << " metros" << std::endl;
    std::cout << "Nível: " << nivel << std::endl;

    imprimirAtributoModificador("Força", forca);
    imprimirAtributoModificador("Destreza", destreza);
    imprimirAtributoModificador("Constituição", constituicao);
    imprimirAtributoModificador("Inteligência", inteligencia);
    imprimirAtributoModificador("Sabedoria", sabedoria);
    imprimirAtributoModificador("Carisma", carisma);

    // Solicitar ao usuário para inserir o equipamento e inventário
    std::cout << "\n=== Equipamento e Inventário ===" << std::endl;
    std::cout << "Digite a arma equipada: ";
    std::getline(std::cin, armaEquipada);

    std::cout << "Digite um item para o inventário: ";
    std::getline(std::cin, itemInventario);

    // Exibir a arma equipada e o inventário do personagem
    std::cout << "\nArma equipada: " << armaEquipada << std::endl;
    std::cout << "Inventário: " << itemInventario << std::endl;

    return 0;
}
