#pragma once

#include "CelulaNum.hpp"

//Estrutura utilizada para auxiliar na obtenção do resultado da expressão numérica
class PilhaNum {
    public:
        PilhaNum();
        virtual ~PilhaNum();
        void Empilha(double numero);
        double Desempilha();
        void Limpa();
        bool Vazia();
    protected:
        CelulaNum* topo;
        int tamanho;
};