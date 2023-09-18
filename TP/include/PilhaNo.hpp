#pragma once

#include "CelulaNo.hpp"

//Estrutura utilizada para auxiliar a inserção da expressão numérica
class PilhaNo {
    public:
        PilhaNo();
        virtual ~PilhaNo();
        void Empilha(No* no);
        No* Desempilha();
        void Limpa();
        bool Vazia();
    protected:
        CelulaNo* topo;
        int tamanho;
};