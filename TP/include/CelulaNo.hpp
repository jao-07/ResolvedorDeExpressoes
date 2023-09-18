#pragma once

#include <cstddef>
#include "No.hpp"

//Classe auxiliar à classe PilhaNo
class CelulaNo {
    public:
        CelulaNo(){
            no = NULL;
            prox = NULL;
        };
    private:
        No *no;
        CelulaNo *prox;
        friend class PilhaNo;
};