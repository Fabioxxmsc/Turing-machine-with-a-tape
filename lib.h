#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 100

// Enumerado para os estados da máquina
enum States{
  q_0       = 0,
  q_li_0    = 1,
  q_li_1    = 2,
  q_teste_0 = 3,
  q_teste_1 = 4,
  q_volta   = 5, 
  q_sim     = 6,
  q_nao     = 7
};

// Simulando um tipo Booleano de dado
typedef enum Boolean{
  true  = 1,
  false = 0
} Bool;

// Estrutura principal da máquina
typedef struct Ribbon{
  char preInput[tam];
  char input[tam];
  int  state;
  int  posicao;
} fita;

// Funções auxiliares
void menu();
void mostraFita(fita _maquina);
void mostraEstado(fita _maquina);
void mostraSaida(fita _maquina);

// Funções para tratar a entrada da fita
fita preencherNulos(fita _maquina);
fita lerPreEntrada(fita _maquina);
Bool validarPreEntrada(fita _maquina);
fita preparaEntrada(fita _maquina);

// Funções de transição da fita
fita calculaPalindromo(fita _maquina);
fita calculaTransicao(fita _maquina);

// Funções para atribuir o estado da máquina
fita setarStateInicial(fita _maquina);
fita setarStateSim(fita _maquina);
fita setarStateNao(fita _maquina);
fita setarStateLiZero(fita _maquina);
fita setarStateLiUm(fita _maquina);
fita setarStateTesteZero(fita _maquina);
fita setarStateTesteUm(fita _maquina);
fita setarStateVolta(fita _maquina);