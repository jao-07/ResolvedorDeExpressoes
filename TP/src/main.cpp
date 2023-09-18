#include <iostream>
#include <fstream>
#include <iomanip>
#include <sys/resource.h>
#include "../include/Expressao.hpp"
#include "../include/Arvore.hpp"

int main(int argc, char *argv[]){
    std::string linha = "", palavra = "";
    std::ifstream arquivo;
    long unsigned int i = 0;
    int k=0;
    Arvore Arv; 

    //Abre o arquivo e se aberto corretamente segue para resto do funcionamento do programa
    arquivo.open(argv[1]);
    if(arquivo.is_open()){
        //Copia as linhas do arquivo na variavel "linha" em cada passada do laço até o fim do arquivo
        while(getline(arquivo, linha)){
            //Separa a primeira palavra da linha e armazena na variavel "palavra"
            for(i = 0; linha[i] != ' ' && i < linha.length(); i++){
                palavra = palavra + linha[i];
            }
            //Se a primeira palavra for "LER", apaga os elementos da Arvore, se existir algo, e separa a segunda palavra e tira a palavra da linha
            if(palavra.compare("LER") == 0){
                Arv.Limpa();
                Arv.LimpaPilha();
                palavra = "";
                linha = linha.substr(4);
                for(int j = 0; linha[j] != ' '; j++){
                    palavra = palavra + linha[j];
                }
                //Se a palavra for "INFIXA", tira a palavra da linha
                if(palavra.compare("INFIXA") == 0){
                    linha = linha.substr(7);
                    palavra = "";
                    i = 0;
                    while(linha[k] == ' ')
                        k++;
                    linha = linha.substr(k);
                    k=0;
                    //Verifica se a linha é valida
                    if(VerificaExpInfixa(linha)){
                        //Se a linha for valida, separa e insere na arvore cada termo da expressão e depois printa na tela que a inserção foi feita
                        while(i < linha.length()){
                            while(linha[i] != ' '){
                                if(i < linha.length()){
                                    palavra = palavra + linha[i];
                                    i++;
                                }
                                else
                                    break;
                            }
                            Arv.InsereInfixa(palavra);
                            palavra = "";
                            while(linha[i] == ' ')
                                i++;
                        }
                        std::cout << "EXPRESSAO OK: " << linha << std::endl << std::endl;
                    } 
                    else //Se a expressão não for válida, printa uma mensagem de erro na tela e a expressão não é armazenada
                        std::cout << "ERRO: " << linha << " NÃO VALIDA" << std::endl;
                }
                //Se a palavra for "POSFIXA", tira a palavra da linha
                else if(palavra.compare("POSFIXA") == 0){
                    linha = linha.substr(8);
                    
                    while(linha[k] == ' ')
                        k++;
                    linha = linha.substr(k);
                    k=0;   
                    palavra = "";
                    //Verifica se a expressão é valida na forma Posfixa e se for, armazena a expressão e printa na tela que a inserção foi feita
                    if (VerificaExpPosfixa(linha)){
                        Arv.InserePosfixa(linha);
                        std::cout << "EXPRESSAO OK: " << linha << std::endl << std::endl;
                    }
                    else //Se a expressão não for válida, printa uma mensagem de erro na tela e a expressão não é armazenada 
                        std::cout << "ERRO: " << linha << "NAO VALIDA" << std::endl;
                }
                else //Se a palavra for inválida, printa na tela um erro.
                    std::cout << "ERRO: Palavra " << palavra << "inválida!!" << std::endl;
                palavra = "";   
            }
            //Se a primeira palavra for "INFIXA", verifica se a Arvore possui alguma coisa
            else if(palavra.compare("INFIXA") == 0){
                //Se a Arvore tiver algo armazenado, imprime a expressão na forma Infixa
                if(Arv.GetRaiz() != NULL){
                    std::cout << "INFIXA: ";
                    Arv.Caminha(2);
                    std::cout << std::endl;
                }
                else //Se não tiver nada armazenado, printa na tela uma mensagem de erro
                    std::cout << "ERRO: EXP NAO EXISTE" << std::endl;
                palavra = "";
            }
            //Se a primeira palavra for "POSFIXA", verifica se a Arvore possui alguma coisa
            else if(palavra.compare("POSFIXA") == 0){
                //Se a Arvore tiver algo armazenado, imprime a expressão na forma Posfixa
                if(Arv.GetRaiz() != NULL){
                    std::cout << "POSFIXA: ";
                    Arv.Caminha(3);
                    std::cout << std::endl;
                }
                else //Se não tiver nada armazenado, printa na tela uma mensagem de erro
                    std::cout << "ERRO: EXP NAO EXISTE" << std::endl;
                palavra = "";
            }
            //Se a primeira palavra for "RESOLVE", verifica se a Arvore possui alguma coisa
            else if(palavra.compare("RESOLVE") == 0){
                //Se a Arvore tiver algo armazenado, imprime o resultado da expressão na tela
                if(Arv.GetRaiz() != NULL){
                    std::cout << std::fixed << std::setprecision(6);
                    Arv.Resultado();

                }
                else //Se não tiver nada armazenado, printa na tela uma mensagem de erro
                    std::cout << "ERRO: EXP NAO EXISTE" << std::endl;
                palavra = "";
            }
            else //Se a primeira palavra não for válida, imprime na tela uma mensagem de erro
                std::cout << "ERRO: COMANDO ERRADO!" << std::endl;
            palavra = "";
            i = 0;
        }
    }
    else
        std::cout << "ERRO: FALHA AO ABRIR O ARQUIVO!" << std::endl;
    return 0;
}