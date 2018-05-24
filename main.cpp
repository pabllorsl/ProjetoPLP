#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> questoesFaceisCG;
vector<string> questaoFacilUmCG;
vector<string> questaoFacilDoisCG;
vector<string> questaoFacilTresCG;
vector<int> premios;

string nome;
string resposta;
bool acertou;
int premioAtual = 0;
int indiceAleatorio;

int pulos = 3;
int cartas = 1;
int universitarios = 1;
int placas = 1;

void iniciarJogo();

int perguntaAleatoria(vector<vector<string>> &vector);

void pararJogo();

void perderJogo();

void ganharJogo();

void iniciarJogo();

void preencherPremios();

void imprimirPremios();

void preencherQuestaoFacilUmCG();

void preencherQuestaoFacilDoisCG();

void preencherQuestaoFacilTresCG();

void imprimirQuestao();

string escolherAlternativa();

bool alternativaCorreta();

void imprimirResultado();

void pararJogo();

void perderJogo();

void atualizarPremio();

int main() {
    iniciarJogo();
    return 0;
}

void iniciarJogo() {
    cout << "Bem vindo(a) ao SHOW DO MILHAO!" << endl << endl;
    cout << "Voce respondera a perguntas do nivel facil, medio e dificil." << endl;
    cout << "Teste seus conhecimentos e concorra ao premio maximo de R$ 1 milhao." << endl << endl;
    cout << "Vamos comecar. Diga-me o seu nome: ";
    cin >> nome;

    preencherPremios();
    preencherQuestaoFacilUmCG();
    preencherQuestaoFacilDoisCG();
    preencherQuestaoFacilTresCG();

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

void preencherQuestaoFacilUmCG() {
    questaoFacilUmCG.push_back("Quanto sao 2+2?");
    questaoFacilUmCG.push_back("A) 5");
    questaoFacilUmCG.push_back("B) 7");
    questaoFacilUmCG.push_back("C) 4");
    questaoFacilUmCG.push_back("D) 2");
    questaoFacilUmCG.push_back("C");
    questaoFacilUmCG.push_back("c");

    questoesFaceisCG.push_back(questaoFacilUmCG);
}

void preencherQuestaoFacilDoisCG() {
    questaoFacilDoisCG.push_back("O que esta escrito na bandeira do Brasil?");
    questaoFacilDoisCG.push_back("A) Ordem e Regresso");
    questaoFacilDoisCG.push_back("B) Ordem e Retrocesso");
    questaoFacilDoisCG.push_back("C) Ordem e Progresso");
    questaoFacilDoisCG.push_back("D) Progresso e Ordem");
    questaoFacilDoisCG.push_back("C");
    questaoFacilDoisCG.push_back("c");

    questoesFaceisCG.push_back(questaoFacilDoisCG);
}

void preencherQuestaoFacilTresCG() {
    questaoFacilTresCG.push_back("Qual o significado da palavra inglesa 'horse'?");
    questaoFacilTresCG.push_back("A) Casa");
    questaoFacilTresCG.push_back("B) Cavalo");
    questaoFacilTresCG.push_back("C) Elefante");
    questaoFacilTresCG.push_back("D) Hipopótamo");
    questaoFacilTresCG.push_back("B");
    questaoFacilTresCG.push_back("b");

    questoesFaceisCG.push_back(questaoFacilTresCG);
}

void imprimirQuestao() {
    cout << "\nPergunta valendo: R$" << premios.at(premioAtual) << endl;
    indiceAleatorio = perguntaAleatoria(questoesFaceisCG);
    for (int i = 0; i < questoesFaceisCG.at(indiceAleatorio).size() - 2; ++i) {
        cout << questoesFaceisCG.at(indiceAleatorio).at(i) << endl;
    }
}

string escolherAlternativa() {
    cout << "\nEscolha uma alternativa:" << endl;
    cin >> resposta;
    return resposta;
}

bool alternativaCorreta() {
    if (questoesFaceisCG.at(indiceAleatorio).at(5).compare(resposta) == 0 ||
        questoesFaceisCG.at(indiceAleatorio).at(6).compare(resposta) == 0) {
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


int perguntaAleatoria(vector<vector<string>> &vector) {
    srand(time(nullptr));
    return rand() % vector.size();
}
