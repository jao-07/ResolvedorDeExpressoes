#pragma once

#include <cstddef>
#include "No.hpp"

//Classe auxiliar à classe PilhaNum
class CelulaNum {
    public:
        CelulaNum(){
            numero = -1.0;
            prox = NULL;
        };
    private:
        double numero;
        CelulaNum *prox;
        friend class PilhaNum;
};