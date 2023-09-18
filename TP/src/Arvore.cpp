#include "../include/Arvore.hpp"

//Construtor da classe Arvore
Arvore::Arvore() {
    Exp = "";
    raiz = NULL;
}

//Destrutor da classe Arvore
Arvore::~Arvore() {
    Limpa();
}

//Função que insere o item na Arvore atraves da chamada de outra função
void Arvore::InsereInfixa(std::string exp){
    InsereRecursivo(raiz,exp);
}

//Função recursiva que caminha nos nós da Arvore e insere no final da Arvore se o item for um parentese ou então subtitui o ultimo parentese pelo item, se esse item for um numero ou um dos 4 simbolos matematicos
void Arvore::InsereRecursivo(No* &p, std::string item){
    if(p==NULL){
        p = new No();
        p->item = item;
        if(VerificaSymbol(item) == 2)
            Pilha.Empilha(p);
    }
    else if(VerificaSymbol(item) == 2 ){
        if(VerificaSymbol(p->item) == 2)
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
    else if(VerificaSymbol(item) == 1 || VerificaNum(item)){
        No *aux = Pilha.Desempilha();
        aux->SetItem(item);
    }
    else
        return;

}

//Função que auxilia a inserção da expressão na forma Posfixa, criando a Arvore de baixo para cima. Se o item for um numero, esse item é empilhado. Se for um simbolo de operação matematica, é criada uma subarvore e esta é empilhada
void Arvore::InserePosfixaTermo(std::string termo){
    No *p = new No();
    if(VerificaNum(termo)){
        p->SetItem(termo);
        Pilha.Empilha(p);
    }
    else if(VerificaSymbol(termo) == 1){
        p->SetItem(termo);
        if(!Pilha.Vazia())
            p->SetDir(Pilha.Desempilha());
        if(!Pilha.Vazia())
            p->SetEsq(Pilha.Desempilha());
        Pilha.Empilha(p);
    }
    else
        std::cout << "Problema ao inserir!!" << std::endl;
}

//Função que insere a expressão na forma Posfixa através da chamada de uma função auxiliar
void Arvore::InserePosfixa(std::string exp){
    long unsigned int i = 0;
    std::string termo = "";
    while(i < exp.length()){
        while(exp[i] != ' '){
            if(i < exp.length()){
                termo = termo + exp[i];
                i++;
            }
            else
                break;
        }
        InserePosfixaTermo(termo);
        termo = "";
        while(exp[i] == ' ')
            i++;
    }
    if(!Pilha.Vazia())
        raiz = Pilha.Desempilha();
    else
        std::cout << "Erro ao Inserir: Pilha Vazia!";
}

//Função auxiliar que caminha entre os nós da Arvore e imprime, auxiliando na tranformação de Infixa para Posfixa
void Arvore::PosOrdem(No *p){
    if(p!=NULL){
        PosOrdem(p->esq);
        PosOrdem(p->dir);
        p->Imprime();
    }
}

//Função auxiliar que caminha entre os nós da Arvore e imprime, auxiliando na tranformação de Posfixa para Infixa
void Arvore::InOrdem(No *p, int a){
    if(p!=NULL){
        if(VerificaSymbol(p->GetItem()) == 1)
            std::cout << "( ";
        if(VerificaNum(p->GetItem()))
            std::cout << "( ";
        InOrdem(p->esq, 0);
        p->Imprime();
        InOrdem(p->dir, 1);
        if(VerificaNum(p->GetItem()))
            std::cout << ") ";
        if(a == 1)
            std::cout << ") ";
    }
}

//Função auxiliar na resolução da expressão
void Arvore::ExpPos(No *p){
    if(p!=NULL){
        ExpPos(p->esq);
        ExpPos(p->dir);
        Exp = Exp + p->GetItem() + " ";
    }
}

//Função que transforma a expressão entre as duas formas possiveis, chamando as funções auxiliares
void Arvore::Caminha(int tipo){
    if(tipo == 2){
        InOrdem(raiz,0);
        std::cout << std::endl;
    }
    else if(tipo == 3){
        PosOrdem(raiz);
        std::cout << std::endl;
    }
    else
        return;
}

//Função recursiva auxiliar que deleta todos os nós abaixo do nó indicado
void Arvore::ApagaRecursivo(No *p){
    if(p!=NULL){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

//Função que apaga todos os nós da Arvore
void Arvore::Limpa(){
    ApagaRecursivo(raiz);
    raiz = NULL;
}

//Função que retorna a raiz da Arvore
No * Arvore::GetRaiz(){
    return raiz;
}

//Função que apaga todos os elementos da Pilha auxiliar da Arvore
void Arvore::LimpaPilha(){
    Pilha.Limpa();
}

//Função que imprime o resultado da expressão, utilizando funções auxiliares
void Arvore::Resultado(){
    ExpPos(raiz);
    long unsigned int i = 0;
    std::string termo = "";
    double aux = 0.0;
    PilhaNum *P = new PilhaNum();
    while(i < Exp.length()){
        while(Exp[i] != ' '){
            if(i < Exp.length()){
                termo = termo + Exp[i];
                i++;
            }
            else
                break;
        }
        if(!AuxResult(termo, P)){
            std::cout << "Operação Inválida: Não é possível dividir por 0!" << std::endl;
            P->Limpa();
            return;
        }
            
        termo = "";
        while(Exp[i] == ' ')
            i++;
    }
    if(!P->Vazia())
        aux = P->Desempilha();
    std::cout << "RESULTADO: " << aux << std::endl << std::endl;
}