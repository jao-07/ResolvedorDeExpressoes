CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Expressao.o $(OBJ)/Arvore.o $(OBJ)/No.o $(OBJ)/PilhaNo.o $(OBJ)/PilhaNum.o
HDRS = $(INC)/Expressao.hpp $(INC)/Arvore.hpp $(INC)/No.hpp $(INC)/PilhaNo.hpp $(INC)/CelulaNo.hpp $(INC)/CelulaNum.hpp $(INC)/PilhaNum.hpp

EXE = $(BIN)/main

all:  $(EXE)

$(BIN)/main: $(OBJS) $(SRC)/main.cpp
	$(CC) -o $(EXE) $(SRC)/main.cpp $(OBJS) -Wall -lm

$(OBJ)/Expressao.o: $(HDRS) $(SRC)/Expressao.cpp
	$(CC) -o $(OBJ)/Expressao.o $(SRC)/Expressao.cpp -c -Wall -lm

$(OBJ)/Arvore.o: $(HDRS) $(SRC)/Arvore.cpp
	$(CC) -o $(OBJ)/Arvore.o $(SRC)/Arvore.cpp -c -Wall -lm

$(OBJ)/No.o: $(HDRS) $(SRC)/No.cpp
	$(CC) -o $(OBJ)/No.o $(SRC)/No.cpp -c -Wall -lm

$(OBJ)/PilhaNo.o: $(HDRS) $(SRC)/PilhaNo.cpp
	$(CC) -o $(OBJ)/PilhaNo.o $(SRC)/PilhaNo.cpp -c -Wall -lm

$(OBJ)/PilhaNum.o: $(HDRS) $(SRC)/PilhaNum.cpp
	$(CC) -o $(OBJ)/PilhaNum.o $(SRC)/PilhaNum.cpp -c -Wall -lm
	
clean:
	rm -f $(EXE) $(OBJS)