#include "../include/No.hpp"

//Construtor da classe No
No::No() {
    item = "";
    esq = NULL;
    dir = NULL;
}

//Função que define o item do nó
void No::SetItem(std::string i){
    item = i;
}

//Função que define o nó esq do nó
void No::SetEsq(No *p){
    esq = p;
}

//Função que define o nó dir do nó
void No::SetDir(No *p){
    dir = p;
}

//Função que retorna o item do nó
std::string No::GetItem(){
    return item;
}

//Função que imprime o item do nó
void No::Imprime(){
    std::cout << item << " ";
}