#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8
#define RANGE 256
int main() {
  //Variáveis
  srand(time(NULL)); 
  unsigned char controle = rand() % RANGE;
  unsigned int op = 0; 
  unsigned int armario = 0;
  unsigned mask = 0x01;
  //Main screen
  while (op != 3) {
    printf("1 - Ocupar armário \n");
    printf("2 - Liberar armário \n");
    printf("3 - Sair \n");
    printf("\n");
    printf("Situação atual dos armários: \n");
      for (int i = 0; i < TAM; i++) 
      {
        //checa se o armario na posicao i está ocupado, se sim retorna 1, se não retorna 0
        printf("%d ", (controle & (1 << i)) ? 1 : 0);
      }
    printf("\n");
    //passa para a próxima Rodada
    printf("Qual sua próxima ação? \n");
    scanf("%d", &op);
    printf("\n");
    //operações escolhidas pelo usuário:
    switch (op) {
      case 1:
        //Ocupar armário
       printf("\n");
        if(controle == 0xFF) {
          //Mascara onde o valor binário é completamente 1, Se a chave de controle for completa, ou seja, todos armários ocupados. O sistema irá alertar.
        printf("Não há armários disponíveis. \n");
      }
      else {
        //caso haja armário disponível.
        do {
        armario = rand() % 8; 
          //escolha de uma vaga aleatória.
        if (controle && (mask << armario)){
          //vai checando se a vaga aleatória está ocupada. Usando um percorrimento de uma máscara fazendo os testes de bits.
        // caso esteja ocupada, o sistema irá escolher outra vaga. Caso não, irá usar um OU para ocupa-la.
          controle = controle | mask << armario;
          break;
        }
           } while (1);
      }
      break;
      case 2:
      //Liberar vaga
      printf("\n");
      //iteração para todos os armários, alterando somente o que desocupará
      printf("Informe qual armário deseja desocupar (0 a 7): \n");
      scanf(" %d", &armario);
      if(armario < 0 || armario > 7){
        //checar se há um armário inexistente
      printf("Armário inválido, informe um valor entre 0 e 7. \n");
      }
      else {
      //NAND desativando o bit do armário desejado
      controle &= (~(mask << armario)); 
        //armario desocupado;
      }
      printf("\n\n");
      break;
      case 3:
      //Input de saída.
      printf("Tenta a sorte prox ano! \n");
      break;
      default:
      printf("Entrada inválida! \n");
    }
    printf("\n");
}
return 0;
}
