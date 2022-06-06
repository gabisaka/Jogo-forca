#include <iostream>
#include <string> 
#include <map>
#include <vector>
#include <fstream>
using namespace std; 

const string PALAVRA_SECRETA = "MELANCIA";

map <char, bool> chutou;

vector<char> chutes_errados;

bool letra_existe (char chute) {
    for (char letra : PALAVRA_SECRETA) {
        if (chute == letra) {
            return true; 
        }
    } 
    return false;
}

bool nao_acertou(){
    for (char letra: PALAVRA_SECRETA) {
        if (!chutou[letra]) {
            return true;
        }
    }
    return false;
}

bool nao_enforcou() {
    return chutes_errados.size() < 5;
}

void imprime_cabecalho () {
    cout << "*********************" << endl;
    cout << "*** JOGO DA FORCA ***" << endl;  
    cout << "*********************" << endl;
    cout << endl; 
}

void imprime_erros () {
    cout << "Chutes errados: ";
        for (char letra: chutes_errados) {
            cout << letra << " ";
        } 
        cout << endl;
}

void imprime_palavra () {
    for(char letra : PALAVRA_SECRETA){
        if (chutou [letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}

void chuta () {
    cout << "Digite seu chute: ";
    char chute;
    cin >> chute; 

    chutou[chute] = true;
        
    if (letra_existe(chute)) {
        cout << "Você acertou! Seu chute está na palavra." << endl; 
    }
    else {
        cout << "Você errou! Seu chute não está na palavra." << endl;
        chutes_errados.push_back (chute); 
    }
    cout << endl;
}

void le_arquivo () {
    ifstream arquivo;
    arquivo.open("palavras.txt");

    int quantidade_palavras;
    arquivo >> quantidade_palavras;

    cout << "O arquivo possui " << quantidade_palavras << " palavras." << endl;

    for (int i=0; i < quantidade_palavras; i++) {
      string palavra_lida; 
      arquivo >> palavra_lida; 
      cout << "Na linha " << i << ":" << palavra_lida << endl;
    }
}

int main () {
    
    imprime_cabecalho();

    le_arquivo();

    while(nao_acertou() && nao_enforcou()){
        
        imprime_erros(); 

        imprime_palavra();

        chuta();
    } 

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;

    if (nao_acertou()) {
        cout << "Você perdeu! Tente novamente" << endl;
    }
    else {
        cout << "Parabéns! Você acertou a palavra secreta" << endl;
    }

}


