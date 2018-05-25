#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ler;

vector<vector<string>> questoesFaceisCC;
vector<vector<string>> questoesMediasCC;
vector<vector<string>> questoesDificeisCC;
vector<vector<string>> questoesFaceisGeral;
vector<vector<string>> questoesMediasGeral;
vector<vector<string>> questoesDificeisGeral;

vector<int> premios;
int numeroDaRodadaAtual = 1; //rodada 1 e 2(perguntas nivel facil), rodada 3 e 4(nivel medio), 5 e 6(nivel dificil)
int indiceDaPerguntaSorteada;
string letraRespostaCertaAtual = "";
string nomeDoJogador;
string resposta;
bool continuar;





char alternativas[5] = {'a', 'b', 'c', 'd', '\0'};
bool acertou;
int premioAtual = 0;
int indiceAleatorio;
int pulos = 3;
int cartas = 1;
int universitarios = 1;
int placas = 1;

void iniciarJogo();
void preencherQuestoes();
void escolherCategoria();
void preencherPremios();


int perguntaAleatoria(vector<vector<string>> &vector);
char letraAleatoria(char alt[]);
void pararJogo();
void perderJogo();
void ganharJogo();
void imprimirPremios();
void imprimirQuestao();
string escolherAlternativa();
bool alternativaCorreta();
void imprimirResultado();
void pararJogo();
void perderJogo();
void atualizarPremio();

int main() {
    iniciarJogo();
    //preencherQuestoesFaceisCG();
    //questoesFaceisCG.erase(questoesFaceisCG.begin()+ indice ); //remover elemento da posicao indice


    return 0;
}

void iniciarJogo() {
    cout << "___________________________________________________________________" << endl;
    cout << "_____________________________ S H O W _____________________________" << endl;
    cout << "_______________________________ D O _______________________________" << endl;
    cout << "___________________________ M I L H A O ___________________________" << endl;
    cout << "___________________________________________________________________" << endl;
    cout << "Teste seus conhecimentos e concorra ao premio maximo de R$ 1 milhao." << endl << endl;
    cout << "Diga-me o seu nome: ";
    cin >> nomeDoJogador;
    preencherQuestoes();
    escolherCategoria();
    preencherPremios();
    cout << "\nBem vindo(a) " << nomeDoJogador << "! O jogo vai comecar, boa sorte!" << endl << endl;
}

void escolherCategoria(){
    cout << "\nQual categoria de questoes voce deseja?" << endl;
    cout << "1) Computacao" << endl;
    cout << "2) Conhecimentos Gerais" << endl;
    cout << "\nDigite o numero da categoria: ";

    do
    {
        cin >> resposta;
        if((resposta.compare("1") != 0) && (resposta.compare("2") != 0)){
            cout << "Categoria invalida. Digite 1 ou 2: ";
        }
    } while((resposta.compare("1") != 0) && (resposta.compare("2") != 0));
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

void preencherQuestoes() {

    /**
    //eh preciso limpar pra garantir que elas vao estar zeradas antes de preenche-las.
    //pois no final de cada rodada sobram elementos dentro da lista
    */
    questoesFaceisCC.clear();
    questoesMediasCC.clear();
    questoesDificeisCC.clear();
    questoesFaceisGeral.clear();
    questoesMediasGeral.clear();
    questoesDificeisGeral.clear();

    vector<string> vetorAux;

    //GERAL
    //faceis
    vetorAux.push_back("Quanto vale 2+2?");
    vetorAux.push_back("A) 5");
    vetorAux.push_back("B) 7");
    vetorAux.push_back("C) 4");
    vetorAux.push_back("D) 2");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesFaceisGeral.push_back(vetorAux);
    vetorAux.clear();

    vetorAux.push_back("O que esta escrito na bandeira do Brasil?");
    vetorAux.push_back("A) Ordem e Regresso");
    vetorAux.push_back("B) Ordem e Retrocesso");
    vetorAux.push_back("C) Ordem e Progresso");
    vetorAux.push_back("D) Progresso e Ordem");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesFaceisGeral.push_back(vetorAux);
    vetorAux.clear();

    vetorAux.push_back("Qual a traducao da palavra inglesa 'horse'?");
    vetorAux.push_back("A) Casa");
    vetorAux.push_back("B) Cavalo");
    vetorAux.push_back("C) Elefante");
    vetorAux.push_back("D) Hipopótamo");
    vetorAux.push_back("B");
    vetorAux.push_back("b");
    questoesFaceisGeral.push_back(vetorAux);
    vetorAux.clear();

    //medias
    vetorAux.push_back("A frase 'I have a dream' é associada a: ");
    vetorAux.push_back("A) George W. Bush");
    vetorAux.push_back("B) Martin Luther King");
    vetorAux.push_back("C) Michael Jackson");
    vetorAux.push_back("D) Snoop Dogg");
    vetorAux.push_back("B");
    vetorAux.push_back("b");
    questoesMediasGeral.push_back(vetorAux);
    vetorAux.clear();

    vetorAux.push_back("Qual o maior e o menor país do mundo? ");
    vetorAux.push_back("A) Russia e Vaticano");
    vetorAux.push_back("B) China e Nepal");
    vetorAux.push_back("C) Guiana Francesa e Estados Unidos");
    vetorAux.push_back("D) Canada e Bangladesh");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesMediasGeral.push_back(vetorAux);
    vetorAux.clear();

    vetorAux.push_back("Qual foi o primeiro recurso usado para explicar a origem das coias?");
    vetorAux.push_back("A) Mitologia");
    vetorAux.push_back("B) Filosofia");
    vetorAux.push_back("C) Matematica");
    vetorAux.push_back("D) Astronomia");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesMediasGeral.push_back(vetorAux);
    vetorAux.clear();

    //dificeis
    vetorAux.push_back("Qual a altura em metros da rede de volei masculino e feminino?");
    vetorAux.push_back("A) 2,5 e 2,0");
    vetorAux.push_back("B) 2,45 para ambos");
    vetorAux.push_back("C) 1,8 e 1,55");
    vetorAux.push_back("D) 2,43 e 2,24");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesDificeisGeral.push_back(vetorAux);
    vetorAux.clear();

    vetorAux.push_back("Em que periodo pre-historico o fogo foi descoberto?");
    vetorAux.push_back("A) Neolitico");
    vetorAux.push_back("B) Paleolitico");
    vetorAux.push_back("C) Neolitico");
    vetorAux.push_back("D) Idade Media");
    vetorAux.push_back("B");
    vetorAux.push_back("b");
    questoesDificeisGeral.push_back(vetorAux);
    vetorAux.clear();

    vetorAux.push_back("Qual desses filmes foi baseado na obra de Shakespeare?");
    vetorAux.push_back("A) Muito Barulho por Nada (2012)");
    vetorAux.push_back("B) Capitães de Areia (2011)");
    vetorAux.push_back("C) A Dama das Camélias (1936)");
    vetorAux.push_back("D) Excalibur");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesDificeisGeral.push_back(vetorAux);
    vetorAux.clear();

    //COMPUTACAO
    //faceis
    vetorAux.push_back("Qual o valor em decimal do binario 00000111");
    vetorAux.push_back("A) 7");
    vetorAux.push_back("B) 8");
    vetorAux.push_back("C) 6");
    vetorAux.push_back("D) 14");
    vetorAux.push_back("A");
    vetorAux.push_back("a");
    questoesFaceisCC.push_back(vetorAux);
    vetorAux.clear();

    vetorAux.push_back("Qual alternativa nao contém um Hardware?");
    vetorAux.push_back("A) Mouse");
    vetorAux.push_back("B) Processador");
    vetorAux.push_back("C) Chipset");
    vetorAux.push_back("D) Debian");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesFaceisCC.push_back(vetorAux);
    vetorAux.clear();

    vetorAux.push_back("E o principal módulo do computador, onde estão conectados todos os periféricos");
    vetorAux.push_back("A) CPU");
    vetorAux.push_back("B) Placa mae");
    vetorAux.push_back("C) Gabinete");
    vetorAux.push_back("D) Entrada usb");
    vetorAux.push_back("B");
    vetorAux.push_back("b");
    questoesFaceisCC.push_back(vetorAux);
    vetorAux.clear();

    //medias
    vetorAux.push_back("Qual alternativa não contém um Hardware?");
    vetorAux.push_back("A) Mouse");
    vetorAux.push_back("B) Processador");
    vetorAux.push_back("C) Chipset");
    vetorAux.push_back("D) Debian");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesMediasCC.push_back(vetorAux);
    vetorAux.clear();

    vetorAux.push_back("Na computação, qual tecnologia substituiu a válvula?");
    vetorAux.push_back("A) Capacitor");
    vetorAux.push_back("B) Resistor");
    vetorAux.push_back("C) Transistor");
    vetorAux.push_back("D) Diodo");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesMediasCC.push_back(vetorAux);
    vetorAux.clear();

    vetorAux.push_back("Dizer que a classe A estende a classe B é o mesmo que dizer que:");
    vetorAux.push_back("A) As classes são irmas");
    vetorAux.push_back("B) A é superclasse de B");
    vetorAux.push_back("C) B é filha de A");
    vetorAux.push_back("D) A é filha de B");
    vetorAux.push_back("D");
    vetorAux.push_back("d");
    questoesMediasCC.push_back(vetorAux);
    vetorAux.clear();

    //dificeis
    vetorAux.push_back("Na ordem cronológica, marque a alternativa correta");
    vetorAux.push_back("A) Ábaco, Eniac, Chip, Transistor e Microprocessador");
    vetorAux.push_back("B) Eniac, Ábaco, Chip, Transistor e Microprocessador");
    vetorAux.push_back("C) Ábaco, Eniac, Transistor, Chip e Microprocessador.");
    vetorAux.push_back("D) Ábaco, Eniac, Chip, Microprocessador e Transistor");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesDificeisCC.push_back(vetorAux);
    vetorAux.clear();

    vetorAux.push_back("Em ordem cronológica, marque a alternativa correta");
    vetorAux.push_back("A) Ábaco, Eniac, Chip, Transistor e Microprocessador");
    vetorAux.push_back("B) Eniac, Ábaco, Chip, Transistor e Microprocessador");
    vetorAux.push_back("C) Ábaco, Eniac, Transistor, Chip e Microprocessador.");
    vetorAux.push_back("D) Ábaco, Eniac, Chip, Microprocessador e Transistor");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesDificeisCC.push_back(vetorAux);
    vetorAux.clear();

    vetorAux.push_back("Pela ordem cronológica, marque a alternativa correta");
    vetorAux.push_back("A) Ábaco, Eniac, Chip, Transistor e Microprocessador");
    vetorAux.push_back("B) Eniac, Ábaco, Chip, Transistor e Microprocessador");
    vetorAux.push_back("C) Ábaco, Eniac, Transistor, Chip e Microprocessador.");
    vetorAux.push_back("D) Ábaco, Eniac, Chip, Microprocessador e Transistor");
    vetorAux.push_back("C");
    vetorAux.push_back("c");
    questoesDificeisCC.push_back(vetorAux);
    vetorAux.clear();
}

void imprimirQuestao() {


}

string escolherAlternativa() {
    string nome_bot = nomeDoJogador;
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

}

void imprimirResultado() {
    cout << "Sua resposta foi: " << resposta << endl;
    if (alternativaCorreta()) {
        cout << "Parabens " << nomeDoJogador << ", voce acertou!" << endl;
        cout << "Voce tem: R$" << premios.at(premioAtual) << endl;
    } else {
        perderJogo();
    }
}

void pararJogo() {
    cout << nomeDoJogador << ", voce decidiu parar o jogo e vai pra casa com R$" << premios.at(premioAtual) << "." << endl;
}

void perderJogo() {
    if (premioAtual == 0) {
        cout << "Infelizmente " << nomeDoJogador << ", voce errou e perdeu tudo." << endl;
        cout << "Boa sorte na proxima vez." << endl;
    }

}

void ganharJogo() {
    cout << "PARABENS " << nomeDoJogador << "! Voce ganhou R$ 1 milhao!!!" << endl;
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

// Essa funcao eh usada para o bot
char letraAleatoria(char alt[]) {
    int randomIndex = rand() % 4;
    return alt[randomIndex];
}
