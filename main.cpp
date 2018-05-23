#include <iostream>
#include <vector>

using namespace std;

string nome;
vector<string> faceis;
vector<string> questao;
vector<int> premios;
string resposta;
bool acertou;
int premioAtual = 0;

void iniciarJogo();

void preencherPerguntasFaceis();

int perguntaAleatoria(const vector<string> &vector);

void pararJogo();

void perderJogo();

void ganharJogo();

void iniciarJogo();

void preencherPremios();

void imprimirPremios();

void preencherQuestao();

void imprimirQuestao();

string escolherAlternativa();

bool alternativaCorreta();

void imprimirResultado();

void pararJogo();

void perderJogo();

void atualizarPremio();

int main() {
    iniciarJogo();

    /*preencherPerguntasFaceis();
    cout << faceis.at(perguntaAleatoria(faceis)) << endl;*/

    return 0;
}

void iniciarJogo() {
    cout << "Bem vindo(a) ao SHOW DO MILHAO!" << endl << endl;
    cout << "Voce respondera a perguntas do nivel facil, medio e dificil." << endl;
    cout << "Teste seus conhecimentos e concorra ao premio maximo de R$ 1 milhao." << endl << endl;
    cout << "Vamos comecar. Diga-me o seu nome: ";
    cin >> nome;

    preencherPremios();
    preencherQuestao();
//    imprimirPremios();
    imprimirQuestao();
    escolherAlternativa();
    imprimirResultado();
}

void preencherPremios() {
    premios.push_back(1000);
    premios.push_back(premios.at(0) * 10);
    premios.push_back(premios.at(1) * 5);
    premios.push_back(premios.at(2) * 2);
    premios.push_back(premios.at(3) * 5);
    premios.push_back(premios.at(4) * 2);
}

void imprimirPremios() {
    for (int i = 0; i < premios.size(); ++i) {
        cout << premios.at(i) << endl;
    }
}

void preencherQuestao() {
    questao.push_back("Quanto sao 2+2?");
    questao.push_back("A) 5");
    questao.push_back("B) 7");
    questao.push_back("C) 4");
    questao.push_back("D) 2");
    questao.push_back("C");
    questao.push_back("c");
}

void imprimirQuestao() {
    cout << "\nPergunta valendo: R$" << premios.at(premioAtual) << endl;
    for (int i = 0; i < questao.size() - 2; ++i) {
        cout << questao.at(i) << endl;
    }
}

string escolherAlternativa() {
    cout << "\nEscolha uma alternativa:" << endl;
    cin >> resposta;
    return resposta;
}

bool alternativaCorreta() {
    if (questao.at(5).compare(resposta) == 0 || questao.at(6).compare(resposta) == 0) {
        acertou = true;
        return true;
    } else {
        acertou = false;
        return false;
    }
}

void imprimirResultado() {
    cout << "Sua resposta foi: " << resposta << endl;
    if (alternativaCorreta()) {
        cout << "Parabens " << nome << ", voce acertou!" << endl;
        cout << "Voce tem: R$" << premios.at(premioAtual) << endl;
    } else {
        perderJogo();
    }
}

void pararJogo() {
    cout << nome << ", voce decidiu parar o jogo e vai pra casa com R$" << premios.at(premioAtual) << "." << endl;
}

void perderJogo() {
    if (premioAtual == 0) {
        cout << "Infelizmente " << nome << ", voce errou e perdeu tudo." << endl;
        cout << "Boa sorte na proxima vez." << endl;
    }

}

void ganharJogo() {
    cout << "PARABENS " << nome << "! Voce ganhou R$ 1 milhao!!!" << endl;
}

void atualizarPremio() {
    if (acertou) {
        premioAtual += 1;
    }
}

/*Faceis: 1mil, 10mil
Medias: 50mil, 100 mil
Dificeis: 500 mil, 1milhao*/

/*void preencherPerguntasFaceis() {
    faceis.push_back("Quem eh o presidente do Brasil?");
    faceis.push_back("Quem sou eu?");
    faceis.push_back("O que eh binario?");
}*/

int perguntaAleatoria(const vector <string> &vector) {
    srand(time(nullptr));
    return rand() % vector.size();
}
