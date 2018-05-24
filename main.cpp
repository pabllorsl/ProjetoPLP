#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*Faceis: 1mil, 10mil
Medias: 50mil, 100 mil
Dificeis: 500 mil, 1milhao*/

vector< vector<string> > questoesFaceisCG;

vector<int> acertar;
vector<int> parar;
vector<int> errar;

char alternativas[5] = {'a', 'b', 'c', 'd', '\0'};
vector<string> opcoes = {"Pular", "Cartas", "Universitario", "Placa", "Parar"};

string nome;
string resposta;
int premioAtual = 0;
int indiceAleatorio;

// Opcoes de ajuda
int pulos = 3;
int cartas = 1;
int universitarios = 1;
int placas = 1;

bool alternativaCorreta();

char letraAleatoria(char alt[]);

int perguntaAleatoria(vector< vector<string> > &vector);

string escolherAlternativa();

void ganharJogo();

void imprimirPremios();

void imprimirQuestao();

void imprimirResultado();

void iniciarJogo();

void introducao();

void limparTela();

void pararJogo();

void perderJogo();

void preencherPremios();

void preencherQuestoesFaceisCG();

void titulo();

int main() {
    iniciarJogo();
    return 0;
}

void titulo() {
    cout << "SHOW DO MILHAO!" << endl;
}

void limparTela() {
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}

void introducao() {
    cout << "Bem vindo(a) ao SHOW DO MILHAO!" << endl << endl;
    cout << "Voce respondera a perguntas do nivel facil, medio e dificil." << endl;
    cout << "Teste seus conhecimentos e concorra ao premio maximo de R$ 1 milhao." << endl << endl;
    cout << "Vamos comecar. Diga-me o seu nome: ";
}

void iniciarJogo() {
    introducao();
    cin >> nome;

    preencherPremios();
    preencherQuestoesFaceisCG();

    limparTela();
    titulo();
    imprimirQuestao();
    escolherAlternativa();
    imprimirResultado();
}

void preencherPremios() {
    acertar.push_back(1000);
    acertar.push_back(acertar.at(0) * 10);
    acertar.push_back(acertar.at(1) * 5);
    acertar.push_back(acertar.at(2) * 2);
    acertar.push_back(acertar.at(3) * 5);
    acertar.push_back(acertar.at(4) * 2);

    parar.push_back(0);
    parar.push_back(acertar.at(1) / 2);
    parar.push_back(acertar.at(2) / 2);
    parar.push_back(acertar.at(3) / 2);
    parar.push_back(acertar.at(4) / 2);
    parar.push_back(acertar.at(5) / 2);

    errar.push_back(0);
    errar.push_back(parar.at(1) / 2);
    errar.push_back(parar.at(2) / 2);
    errar.push_back(parar.at(3) / 2);
    errar.push_back(parar.at(4) / 2);
    errar.push_back(0);

}

/*void imprimirPremios() {
    for (int i = 0; i < acertar.size(); ++i) {
        cout << "Acertar: R$" << acertar.at(i) << " | Parar: R$ " << parar.at(i) << " | Errar: R$" << errar.at(i)
             << endl;
    }
}*/

void preencherQuestoesFaceisCG() {
    vector<string> vetor1;

    vetor1.push_back("Quanto sao 2+2?");
    vetor1.push_back("A) 5");
    vetor1.push_back("B) 7");
    vetor1.push_back("C) 4");
    vetor1.push_back("D) 2");
    vetor1.push_back("C");
    vetor1.push_back("c");

    questoesFaceisCG.push_back(vetor1);

    vector<string> vetor2;

    vetor2.push_back("O que esta escrito na bandeira do Brasil?");
    vetor2.push_back("A) Ordem e Regresso");
    vetor2.push_back("B) Ordem e Retrocesso");
    vetor2.push_back("C) Ordem e Progresso");
    vetor2.push_back("D) Progresso e Ordem");
    vetor2.push_back("C");
    vetor2.push_back("c");

    questoesFaceisCG.push_back(vetor2);

    vector<string> vetor3;

    vetor3.push_back("Qual o significado da palavra inglesa 'horse'?");
    vetor3.push_back("A) Casa");
    vetor3.push_back("B) Cavalo");
    vetor3.push_back("C) Elefante");
    vetor3.push_back("D) Hipopótamo");
    vetor3.push_back("B");
    vetor3.push_back("b");

    questoesFaceisCG.push_back(vetor3);
}

void imprimirQuestao() {
    cout << "\nPergunta valendo: R$" << acertar.at(premioAtual) << " | Parar: R$" << parar.at(premioAtual)
         << " | Errar: R$" << errar.at(premioAtual) << endl;
    indiceAleatorio = perguntaAleatoria(questoesFaceisCG);
    for (int i = 0; i < questoesFaceisCG.at(indiceAleatorio).size() - 2; ++i) {
        cout << questoesFaceisCG.at(indiceAleatorio).at(i) << endl;
    }
}

string escolherAlternativa() {
    string nome_bot = nome;
    transform(nome_bot.begin(), nome_bot.end(), nome_bot.begin(), ::tolower);
    cout << "\nEscolha uma alternativa:" << endl;
    if (nome_bot.compare("bot") == 0) {
        resposta = letraAleatoria(alternativas);
    } else {
        cin >> resposta;
    }

    return resposta;
}

bool alternativaCorreta() {
    if (questoesFaceisCG.at(indiceAleatorio).at(5).compare(resposta) == 0 ||
        questoesFaceisCG.at(indiceAleatorio).at(6).compare(resposta) == 0) {
        premioAtual += 1;
        return true;
    } else {
        return false;
    }

    /*if (resposta.compare("5") == 0) {
        pararJogo();
    } else {
        if (questoesFaceisCG.at(indiceAleatorio).at(5).compare(resposta) == 0 ||
            questoesFaceisCG.at(indiceAleatorio).at(6).compare(resposta) == 0) {
            premioAtual += 1;
            return true;
        } else {
            return false;
        }
    }*/
}

void imprimirResultado() {
    if (resposta.compare("A") == 0 || resposta.compare("a") == 0 || resposta.compare("B") == 0 ||
        resposta.compare("b") == 0 || resposta.compare("C") == 0 || resposta.compare("c") == 0 ||
        resposta.compare("D") == 0 || resposta.compare("d") == 0) {
        cout << "Sua resposta foi: " << resposta << endl;
    } else if (resposta.compare("1") == 0 || resposta.compare("2") == 0 || resposta.compare("3") == 0 ||
               resposta.compare("4") == 0 || resposta.compare("5") == 0) {
        cout << "Voce escolheu a opcao: " << resposta << stoi(resposta) << endl;
    }

    if (alternativaCorreta()) {
        cout << "Parabens " << nome << ", voce acertou!" << endl;
        cout << "Voce tem: R$" << acertar.at(premioAtual - 1) << endl;
    } else {
        perderJogo();
    }
}

void pararJogo() {
    cout << nome << ", voce decidiu parar o jogo e vai pra casa com R$" << parar.at(premioAtual) << endl;
}

void perderJogo() {
    if (premioAtual == 0 || premioAtual == 5) {
        cout << "Infelizmente " << nome << ", voce errou e perdeu tudo." << endl;
        cout << "Boa sorte na proxima vez." << endl;
    } else {
        cout << "Infelizmente " << nome << ", voce errou e so ganhou R$" << errar.at(premioAtual) << endl;
        cout << "Boa sorte na proxima vez." << endl;
    }
}

void ganharJogo() {
    cout << "PARABENS " << nome << "! Voce ganhou R$ 1 milhao!!!" << endl;
}

int perguntaAleatoria(vector< vector<string> > &vector) {
    srand(time(0));
    return rand() % vector.size();
}

// Essa funcao eh usada para o bot
char letraAleatoria(char alt[]) {
    int randomIndex = rand() % 4;
    return alt[randomIndex];
}

/*void respostaInvalida() {
    if (!alternativaOpcaoValida()) {
        cout << "Alternativa/opcao invalida. Tente novamente:" << endl;
        cout << "Alternativas: A/a, B/b, C/c, D/d" << endl;
        cout << "Opcoes: 1, 2, 3, 4 ou 5" << endl;
        escolherAlternativa();
    }

}

bool alternativaOpcaoValida() {
    if (resposta.compare("A") == 0 || resposta.compare("a") == 0 || resposta.compare("B") == 0 ||
        resposta.compare("b") == 0 || resposta.compare("C") == 0 || resposta.compare("c") == 0 ||
        resposta.compare("D") == 0 || resposta.compare("d") == 0 || resposta.compare("1") == 0 ||
        resposta.compare("2") == 0 || resposta.compare("3") == 0 ||
        resposta.compare("4") == 0 || resposta.compare("5") == 0) {
        return true;
    }
}*/