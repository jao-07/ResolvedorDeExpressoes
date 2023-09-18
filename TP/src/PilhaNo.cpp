#include "../include/PilhaNo.hpp"

//Construtor da classe PilhaNo
PilhaNo::PilhaNo(){
    topo = NULL;
    tamanho = 0;
}

//Destrutor da classe PilhaNo
PilhaNo::~PilhaNo() {
    Limpa();
}

//Função que retorna se a Pilha está vazia ou não
bool PilhaNo::Vazia(){
    return tamanho == 0;
}

//Função que empilha um nó na Pilha
void PilhaNo::Empilha(No *no){
    CelulaNo *nova;
    nova = new CelulaNo();
    nova->no = no;
    nova->prox = topo;
    topo = nova;
    tamanho++;
}

//Função que desempilha o nó do topo e retorna esse nó
No* PilhaNo::Desempilha(){
    No *aux; CelulaNo *p;
    if(tamanho != 0){
        aux = topo->no;
        p = topo;
        topo = topo->prox;
        delete p;
        tamanho--;
        return aux;
    }
    else
        return NULL;
    
};

//Função que apaga todos os nós da Pilha
void PilhaNo::Limpa(){
    while(!Vazia())
    Desempilha();
}