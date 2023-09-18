#pragma once

#include <cctype>
#include <string>
#include <iostream>
#include "PilhaNum.hpp"

//Arquivo que contém as funções que auxiliam na verificação da expressão e na obtenção do resultado

bool VerificaNum(std::string s);

int VerificaSymbol(std::string s);

bool VerificaExpInfixa(std::string s);

bool VerificaExpPosfixa(std::string s);

bool AuxResult(std::string s, PilhaNum* &P);