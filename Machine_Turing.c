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