#include <iostream>
#include <vector>

using namespace std;

vector<string> faceis;
string nome;
int valor = 0;

void iniciaJogo();

void preencherPerguntasFaceis();

int perguntaAleatoria(const vector<string> &vector);

void paraJogo();

void perdeJogo();

void ganhaJogo();

int main() {
    iniciaJogo();
    cout << "Seu nome eh: " << nome << endl;
    cout << "Você tem: R$" << valor << endl;

    preencherPerguntasFaceis();
    cout << faceis.at(perguntaAleatoria(faceis)) << endl;

    paraJogo();
    perdeJogo();
    ganhaJogo();

    return 0;
}

void iniciaJogo() {
    cout << "Bem vindo(a) ao SHOW DO MILHÃO!" << endl << endl;
    cout << "Você responderá à perguntas do nível fácil ao nível díficil." << endl;
    cout << "Teste seus conhecimentos e concorra ao prêmio máximo de R$ 1 milhão." << endl << endl;
    cout << "Vamos começar. Diga-me o seu nome: ";
    cin >> nome;
}

void preencherPerguntasFaceis() {
    faceis.push_back("Quem eh o presidente do Brasil?");
    faceis.push_back("Quem sou eu?");
    faceis.push_back("O que é binário?");
}

int perguntaAleatoria(const vector <string> &vector) {
    srand(time(nullptr));
    return rand() % vector.size();
}

void paraJogo() {
    cout << nome << ", você decidiu parar o jogo e vai pra casa com R$" << valor << "." << endl;
}

void perdeJogo() {
    cout << nome << ", infelizmente você errou a resposta e vai pra casa com R$" << valor << endl;
}

void ganhaJogo() {
    cout << "PARABÉNS " << nome << "! Você ganhou R$ 1 milhão!!!" << endl;
}
