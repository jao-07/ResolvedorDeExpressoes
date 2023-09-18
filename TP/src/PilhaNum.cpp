#include "../include/PilhaNum.hpp"

//Contrutor da classe PilhaNum
PilhaNum::PilhaNum(){
    topo = NULL;
    tamanho = 0;
}

//Destrutor da classe PilhaNum
PilhaNum::~PilhaNum() {
    Limpa();
}

//Função que retorna se a Pilha está vazia ou não
bool PilhaNum::Vazia(){
    return tamanho == 0;
}

//Função que empilha um numero na Pilha
void PilhaNum::Empilha(double numero){
    CelulaNum *nova;
    nova = new CelulaNum();
    nova->numero = numero;
    nova->prox = topo;
    topo = nova;
    tamanho++;
}

//Função que desempilha o numero do topo e retorna esse numero
double PilhaNum::Desempilha(){
    double aux; CelulaNum *p;
    if(tamanho != 0){
        aux = topo->numero;
        p = topo;
        topo = topo->prox;
        delete p;
        tamanho--;
        return aux;
    }
    else
        return -1;
    
};

//Função que apaga todos os numeros da Pilha
void PilhaNum::Limpa(){
    while(!Vazia())
    Desempilha();
}