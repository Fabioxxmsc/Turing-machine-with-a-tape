#include "lib.h"

void menu(){
  printf("\n###Máquina de Turing###\n");
  printf("-> Entrada cadeia de binário\n");
  printf("-> Verificação se a entrada é um palíndromo\n");
  printf("-> Saída qsim ou qnão\n");
  printf("\nEntrada: ");
}

/*
  Seta o caractere '\0' em todas as posições dos array's.
  preinput é a entrada do usuário, com os valores originais
  input é a entrada onde será tratada com caracteres especiais
*/
fita preencherNulos(fita _maquina){
  memset(_maquina.input, '\0', sizeof(_maquina.input));
  memset(_maquina.preInput, '\0', sizeof(_maquina.preInput));
  return _maquina;
}

fita lerPreEntrada(fita _maquina){
  fgets(_maquina.preInput, tam, stdin);
  return _maquina;
}

/*
  Garante a entrada só de binários
*/
Bool validarPreEntrada(fita _maquina){
  Bool valido = true;
  for (int i = 0; _maquina.preInput[i] != '\0'; i++){
    if ((_maquina.preInput[i] != '0') && (_maquina.preInput[i] != '1') && (_maquina.preInput[i] != '\n')){
      valido = false;
      break;
    }
  }
  return valido;
}

/*
  input recebe a concatenação do caractere > usado como inicio,
  depois a preinput com os valores binários, e também
  o caractere ' '(espaço), definido com fim da entrada,
  também é setado a posição inicial do cabeçote
*/
fita preparaEntrada(fita _maquina){
  int tamStr = strlen(_maquina.preInput) -1;
  if (_maquina.preInput[tamStr] == '\n')
    _maquina.preInput[tamStr] = ' ';
  strcat(_maquina.input, ">");
  strcat(_maquina.input, _maquina.preInput);
  _maquina.posicao = -1;
  return _maquina;
}

fita calculaPalindromo(fita _maquina){
  _maquina = setarStateInicial(_maquina);
  _maquina.posicao = 0;
  _maquina = calculaTransicao(_maquina);
  return _maquina;
}

fita calculaTransicao(fita _maquina){
  if (_maquina.state == q_0){
    if (_maquina.input[_maquina.posicao] == '>'){
      _maquina.posicao++;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);
    }else if (_maquina.input[_maquina.posicao] == '0'){
      _maquina.input[_maquina.posicao] = '>';
      _maquina = setarStateLiZero(_maquina);
      _maquina.posicao++;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);
    }else if (_maquina.input[_maquina.posicao] == '1'){
      _maquina.input[_maquina.posicao] = '>';
      _maquina = setarStateLiUm(_maquina);
      _maquina.posicao++;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);
    }else{
      _maquina = setarStateSim(_maquina);
      mostraFita(_maquina);
    }
  }else if (_maquina.state == q_li_1){
    if (_maquina.input[_maquina.posicao] == '0'){
      _maquina.posicao++;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);
    }else if (_maquina.input[_maquina.posicao] == '1'){
      _maquina.posicao++;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);      
    }else if (_maquina.input[_maquina.posicao] == ' '){
      _maquina = setarStateTesteUm(_maquina);
      _maquina.posicao--;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);
    }
  }else if (_maquina.state == q_li_0){
    if (_maquina.input[_maquina.posicao] == '0'){
      _maquina.posicao++;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);
    }else if (_maquina.input[_maquina.posicao] == '1'){
      _maquina.posicao++;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);      
    }else if (_maquina.input[_maquina.posicao] == ' '){
      _maquina = setarStateTesteZero(_maquina);
      _maquina.posicao--;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);
    }
  }else if (_maquina.state == q_teste_1){
    if (_maquina.input[_maquina.posicao] == '>'){
      _maquina = setarStateSim(_maquina);
      mostraFita(_maquina);
    }else if (_maquina.input[_maquina.posicao] == '0'){
      mostraFita(_maquina);
      _maquina = setarStateNao(_maquina);
    }else if (_maquina.input[_maquina.posicao] == '1'){
      _maquina.input[_maquina.posicao] = ' ';
      _maquina = setarStateVolta(_maquina);
      _maquina.posicao--;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);      
    }
  }else if (_maquina.state == q_teste_0){
    if (_maquina.input[_maquina.posicao] == '>'){
      mostraFita(_maquina);
      _maquina = setarStateSim(_maquina);
    }else if (_maquina.input[_maquina.posicao] == '0'){
      _maquina.input[_maquina.posicao] = ' ';
      _maquina = setarStateVolta(_maquina);
      _maquina.posicao--;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);
    }else if (_maquina.input[_maquina.posicao] == '1'){
      mostraFita(_maquina);
      _maquina = setarStateNao(_maquina);
    }
  }else if (_maquina.state == q_volta){
    if (_maquina.input[_maquina.posicao] == '>'){
      _maquina = setarStateInicial(_maquina);
      _maquina.posicao++;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);
    }else if (_maquina.input[_maquina.posicao] == '0'){
      _maquina.posicao--;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);
    }else if (_maquina.input[_maquina.posicao] == '1'){
      _maquina.posicao--;
      mostraFita(_maquina);
      _maquina = calculaTransicao(_maquina);
    }
  }  
  return _maquina;
}

fita setarStateInicial(fita _maquina){
  _maquina.state = q_0;
  return _maquina;
}

fita setarStateSim(fita _maquina){
  _maquina.state = q_sim;
  return _maquina;
}

fita setarStateNao(fita _maquina){
  _maquina.state = q_nao;
  return _maquina;
}

fita setarStateLiZero(fita _maquina){
  _maquina.state = q_li_0;
  return _maquina;
}

fita setarStateLiUm(fita _maquina){
  _maquina.state = q_li_1;
  return _maquina;
}

fita setarStateTesteZero(fita _maquina){
  _maquina.state = q_teste_0;
  return _maquina;
}

fita setarStateTesteUm(fita _maquina){
  _maquina.state = q_teste_1;
  return _maquina;
}

fita setarStateVolta(fita _maquina){
  _maquina.state = q_volta;
  return _maquina;
}

void mostraFita(fita _maquina){
  printf("\nFita  = [");
  for (int i = 0; _maquina.input[i] != '\0'; i++){
    if (_maquina.input[i] != '\0'){
      if (i == _maquina.posicao)
        printf(",");
      printf("%c", _maquina.input[i]);
    }
  }
  printf("] ");
  mostraEstado(_maquina);
}

void mostraEstado(fita _maquina){
  printf("Estado = [%d, ", _maquina.state);

  if (_maquina.state == q_0)
    printf("q_0]");
  else if (_maquina.state == q_li_0)
    printf("q_li_0]");
  else if (_maquina.state == q_li_1)
    printf("q_li_1]");
  else if (_maquina.state == q_teste_0)
    printf("q_teste_0]");
  else if (_maquina.state == q_teste_1)
    printf("q_teste_1]");
  else if (_maquina.state == q_volta)
    printf("q_volta]");
  else if (_maquina.state == q_nao)
    printf("q_nao]");
  else if (_maquina.state == q_sim)
    printf("q_sim]");
}

void mostraSaida(fita _maquina){
  if (_maquina.state == q_sim)
    printf("\n\nSaída = [Sim]\n\n");
  else if (_maquina.state == q_nao)
    printf("\n\nSaída = [Não]\n\n");
  else
    printf("\n\nSaída = [Transição Impossível]\n\n");
}