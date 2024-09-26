#include <stdio.h>

#define adminpasswd 27341

// Coffee Ingredient(s) Constants
#define beansg 8

// Espresso
#define espresswaterml 30
#define espresspriceaed 3.5

// Cappuccino
#define cappuwaterml 30
#define cappumilkml 70
#define cappupriceaed 4.5

// Mocha
#define mochawaterml 39
#define mochamilkml 160
#define mochachocml 30
#define mochapriceaed 5.5

// Low Threshold Amount
#define beanslowg 8
#define waterlowml 39
#define milklowml 70
#define choclowml 30

int main(){

  int menu;

  while (1){
  printf("Coffee Maker Interface\n 1. Order coffee\n 2. ADMIN MODE (for operators)\n 0. Exit\n");
  scanf("%d", &menu);

  // Switch statement
  switch (menu){
	  case 1:
		  void ordercoffee();
	case 2:
		  printf("Admin mode menu.\n");
		  break;
  }
  if (menu==0){
	  break;
  }
}
}
void ordercoffee(){
        int z;
        printf("You will now order coffee!\n\n");
        while(1){
          printf("put 0 otherwise you stay here forever");
          scanf("%d", &z);
          if(z==0)
          break;
}
}
