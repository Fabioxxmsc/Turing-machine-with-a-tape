/* Máquina de Turing com somente 1 fita, que decide se uma cadeia
 * binária x é um palíndromo.
 * 
 * Compilar: gcc Machine_Turing.c -o functions.c -o main -Wall
 * 
 * Alunos: Fabio Antonio Ribeiro Dos Santos e 
 *         Fabio Alecsandro Bacin 
 */

#include "functions.c"

/**
 * Usado struct, então escolhido usar um padrão
 * onde passa um struct do tipo fita por parâmetro
 * e na maioria das funções recebemos um tipo struct
 * fita 
 */

int main(){
  fita maquina;
  menu();
  maquina = preencherNulos(maquina);
  maquina = lerPreEntrada(maquina);
  if (validarPreEntrada(maquina)){
    maquina = preparaEntrada(maquina);
    maquina = calculaPalindromo(maquina);
    mostraSaida(maquina);
  }else{
    printf("\n A entrada não é uma cadeia de binários!!!\n");
  }
  return 0;
}