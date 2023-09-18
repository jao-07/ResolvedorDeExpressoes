#pragma once

#include <string>
#include <iostream>

//Classe utilizada para auxiliar a contrução da estrutura Arvore
class No {
    public:
        No();
        void SetItem(std::string i);
        std::string GetItem();
        void SetEsq(No* p);
        void SetDir(No* p);
        void Imprime();
    private:
        std::string item;
        No *esq;
        No *dir;
    friend class Arvore;
};