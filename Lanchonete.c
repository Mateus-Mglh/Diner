#include <stdio.h>
#include <string.h>

#define MAX_STRING 150
#define MAX_ORDER 5

typedef struct {
  char productName[MAX_STRING];
  int productQtt;
  int productCode;
  float productPrice;
} Product;

void flush();
int totalOrder;
Product clientOrder[MAX_ORDER];

Product order() {
  printf("- - - - Pedido - - - -\n");
  
  Product p;
  printf("Produto: ");
  fgets(p.productName, MAX_STRING, stdin);
  p.productName[strcspn(p.productName, "\n")] = '\0';

  printf("Codigo: ");
  scanf("%d", &p.productCode);
  flush();

  switch(p.productCode) {
    case 100:
      p.productPrice = 1.10;
      printf("Quantidade: ");
      scanf("%d", &p.productQtt);
      break;
    case 101:
      p.productPrice = 2.30;
      printf("Quantidade: ");
      scanf("%d", &p.productQtt);
      flush();
      break;
    case 102:
      p.productPrice = 1.50;
      printf("Quantidade: ");
      scanf("%d", &p.productQtt);
      flush();
      break;
    case 103:
      p.productPrice = 2.10;
      printf("Quantidade: ");
      scanf("%d", &p.productQtt);
      flush();
      break;
    case 104:
      p.productPrice = 1.30;
      printf("Quantidade: ");
      scanf("%d", &p.productQtt);
      flush();
      break;
    case 105:
      p.productPrice = 1.00;
      printf("Quantidade: ");
      scanf("%d", &p.productQtt);
      flush();
      break;
    default:
      printf("Codigo invalido!");
      printf("\n");
      break;
  }
  int totalQtt = p.productQtt;
  totalQtt++;
  printf("%d", totalQtt);
  printf("\n");
  return p;
}


void printMenu() {
  printf("Cardapio:\n");
  printf("Cachorro quente   (cod. 100) ...... R$1,10\n");
  printf("Bauru simples     (cod. 101) ...... R$2,30\n");
  printf("Bauru c/ovo       (cod. 102) ...... R$1,50\n");
  printf("Hamburguer        (cod. 103) ...... R$2,10\n");
  printf("Cheeseburguer     (cod. 104) ...... R$1,30\n");
  printf("Refrigerante      (cod. 105) ...... R$1,00\n");
  printf("\n");
}


void printfOrder() {
  printf("- - - - Visao do Pedido - - - -\n");

  for(int i = 0; i < totalOrder; i++) {
    printf("Produto: %s\n", clientOrder[i].productName);
    printf("Quantidade: %d\n", clientOrder[i].productQtt);
    printf("Preco: R$%.2f\n", clientOrder[i].productPrice);
    printf("\n");
  }
}


void flush() {        
  while(getchar() != '\n');
}


int main() {
  printf("- - - - Kelvin Lanches - - - -\n");
  printf("Comprem, se nao passarao fome aqui!\n");
  printf("\n");

  int option;
  do {
    printf("- - - - Menu de opcoes - - - -\n");
    printf("1. Ver cardapio\n2. Fazer pedido\n3. Ver pedido\n4. Finalizar pedido\n");
    printf("Escolha uma opcao:  ");
    scanf("%d", &option);
    flush();
    printf("\n");

    switch (option) {
    case 1:
      printMenu();
      break;
    case 2:
      if(totalOrder < MAX_ORDER) {
        clientOrder[totalOrder] = order();
        totalOrder++;
      }
      else if(totalOrder == MAX_ORDER) {
        printf("Carrinho cheio! (%d/%d)", totalOrder, MAX_ORDER);
        printf("\n");
      }
      break;
    case 3:
      printfOrder();
      break;
    case 4:
      break;
    default:
      printf("Opcao invalida!\n");
      break;
    }
  } while(option != 4);
  return 0;
}