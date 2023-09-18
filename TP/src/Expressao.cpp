#include "../include/Expressao.hpp"
#include <iomanip>

//Função auxiliar que verifica se a string é um numero valido e retorna true se for, e false se não for
bool VerificaNum(std::string s){
    int cont = 0;
    for(long unsigned int i=0; i<s.length(); i++){
        if(!isdigit(s[i]) && s[i] != '.')
            return false;
        if(s[i] == '.')
            cont++;
    }
    if(cont >= 2)
        return false;
    return true;
}

//Função auxiliar que verifica se a string é algum dos simbolos da expressão, e retorna 1 se for algum simbolo de operação, 2 se for "(", 3 se for ")" e 0 se não for nenhum dos anteriores
int VerificaSymbol(std::string s){
    if(s.compare("+") == 0 || s.compare("-") == 0 || s.compare("*") == 0 || s.compare("/") == 0)
        return 1;
    if(s.compare("(") == 0)
        return 2;
    if(s.compare(")") == 0)
        return 3;
    return 0;
}

//Função auxiliar que verifica se a expressão é valida na forma Infixa
bool VerificaExpInfixa(std::string s){
    long unsigned int i = 0, contNum = 0, contSymb = 0, contPar1 = 0, contPar2 = 0, contTermo = 0;
    std::string primeiro = "";
    bool frst = true;
    primeiro = primeiro + s[0];
    std::string aux = "";
    while(s.length() > 0){
        for(i=0; s[i] != ' '; i++){
            if(i >= s.length())
                break;
            aux = aux + s[i];
        }
        if(i >= s.length())
            s = "";
        else
            s = s.substr(i+1);

        if(!(aux.length() > 0)){
            i++;
            continue;
        }
        if(!VerificaNum(aux) && !VerificaSymbol(aux))
            return false;
        if(VerificaNum(aux)){
            contNum++;
            contSymb = 0;
            contTermo++;
        }  
        if(VerificaSymbol(aux) == 1){
            contSymb++;
            contNum = 0;
            contTermo++;
        }
        if(VerificaSymbol(aux) == 2)
            contPar1++;
        if(VerificaSymbol(aux) == 3)
            contPar2++;
        if(contNum > 1 || contSymb > 1)
            return false;
        if((VerificaSymbol(aux) == 1 || VerificaNum(aux)) && frst){
            primeiro = aux;
            frst = false;
        }
        aux = "";
    }
    if(contPar1 != contPar2 || !VerificaNum(primeiro) || contSymb >= contNum || contTermo != contPar1)
        return false;
    else
        return true;
}

//Função auxiliar que verifica se a expressão é valida na forma Posfixa
bool VerificaExpPosfixa(std::string s){
    long unsigned int i = 0, contNum = 0;
    std::string primeiro = "", ultimo = ""; 
    primeiro = primeiro + s[0];
    std::string aux = "";
    while(s.length() > 0){
        for(i=0; s[i] != ' '; i++){
            if(i >= s.length())
                break;
            aux = aux + s[i];
        }
        
        if(i >= s.length())
            s = "";
        else
            s = s.substr(i+1);

        //if(aux == "")
            //continue;
        if(!(aux.length() > 0)){
            i++;
            continue;
        }
        
        if(!VerificaNum(aux) && VerificaSymbol(aux) != 1)
            return false;
        if(VerificaNum(aux))
            contNum++;  
        if(VerificaSymbol(aux) == 1)
            contNum--;
        if(contNum == 0)
            return false;  
        ultimo = aux;
        aux = "";
    }
    if(!VerificaNum(primeiro) || VerificaSymbol(ultimo) != 1 || contNum != 1)
        return false;
    else
        return true;
}

//Função auxiliar que ajuda na resolução da solução utilizando Pilhas auxiliares
bool AuxResult(std::string s, PilhaNum* &P){
    double aux1 = 0.0;
    double aux2 = 0.0;
    double aux3 = 0.0;
    if(VerificaNum(s)){
        aux1 = std::stod(s);
        P->Empilha(aux1);
    }
    else if(s.compare("/") == 0){
        aux1 = P->Desempilha();
        aux2 = P->Desempilha();
        if(aux1 != 0){
            aux3 = aux2 / aux1;
            P->Empilha(aux3);
        }   
        else
            return false; 
    }
    else if(s.compare("+") == 0){
        aux1 = P->Desempilha();
        aux2 = P->Desempilha();
        aux3 = aux2 + aux1;
        P->Empilha(aux3);
    }
    else if(s.compare("*") == 0){
        aux1 = P->Desempilha();
        aux2 = P->Desempilha();
        aux3 = aux2 * aux1;
        P->Empilha(aux3);
    }
    else if(s.compare("-") == 0){
        aux1 = P->Desempilha();
        aux2 = P->Desempilha();
        aux3 = aux2 - aux1;
        P->Empilha(aux3);
        
    }
    return true;
}