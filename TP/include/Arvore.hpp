#pragma once

#include "No.hpp"
#include "PilhaNo.hpp"
#include "PilhaNum.hpp"
#include "Expressao.hpp"
#include <iomanip>

//Estrutura utilizada para armazenar a expressão numérica

class Arvore {
    public:
        Arvore();
        ~Arvore();
        void InsereInfixa(std::string exp);
        void InserePosfixa(std::string exp);
        void Caminha(int tipo);
        void Limpa();
        No* GetRaiz();
        void LimpaPilha();
        void Resultado();
    private:
        void InsereRecursivo(No* &p, std::string item);
        void ApagaRecursivo(No* p);
        void InserePosfixaTermo(std::string termo);
        void InOrdem(No* p, int a);
        void PosOrdem(No* p);
        void ExpPos(No *p);
        No *raiz;
        PilhaNo Pilha;
        std::string Exp;
};