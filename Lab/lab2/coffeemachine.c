#include <stdio.h>
#include <unistd.h>

#define adminPasswd 27341

// Coffee Ingredient(s) Constants
#define beansg 8

// Espresso
#define espressWatermL 30
#define espressPriceAED 3.5

// Cappuccino
#define cappuWatermL 30
#define cappuMilkmL 70
#define cappuPriceAED 4.5

// Mocha
#define mochaWatermL 39
#define mochaMilkmL 160
#define mochaChocmL 30
#define mochaPriceAED 5.5

// Low Threshold Amount
#define beansLowg 8
#define waterLowmL 39
#define milkLowmL 70
#define chocLowmL 30

int coffeeBeansg = 50;
int watermL = 250;
int milkmL = 500;
int chocSyrup = 150;
float priceAED = 0.00;
float payAED = 0.00;
float inputAED = 0.00;

int espressCount;
int espressTotal;
int cappuCount;
int cappuTotal;
int mochaCount;
int mochaTotal;

int main(){

  int menu;

  while (1){
  printf("Coffee Maker Interface\n 1. Order coffee\n 2. ADMIN MODE (for operators)\n 0. Exit\n");
  scanf("%d", &menu);
  if (menu==0){
	  break;
  }
  // Switch statement
  switch (menu){
	  case 1:
	int coffeeChoice;
	while(1){
	printf("Pick your coffee cup of choice!\n 1. Espresso\n 2. Cappuccino\n 3. Mocha\n 9. Confirm order and buy\n 0. Exit this menu\n");
	scanf("%d", &coffeeChoice);
	if (coffeeChoice==0){
		break;
	}
	  switch (coffeeChoice){
		case 1:
			printf("How many Espressos would you like to order? ");
			scanf("%d", &espressCount);
			espressTotal += espressCount;
			priceAED += (espressCount * espressPriceAED);
			printf("\nYour order costs $%.2f\n\n", priceAED);
			break;
		case 2:
			printf("How many Cappuccinos would you like to order? ");
			scanf("%d", &cappuCount);
			cappuTotal += cappuCount;
			priceAED += (cappuCount * cappuPriceAED);
			printf("\nYour order costs $%.2f\n\n", priceAED);
			break;
		case 3:
			printf("How many Mochas would you like to order? ");
			scanf("%d", &mochaCount);
			mochaTotal += mochaCount;
			priceAED += (mochaCount * mochaPriceAED);
			printf("\nYour order costs $%.2f\n\n", priceAED);
			break;
		case 9:
			printf("Insert $%.2f in paper/coins: ", priceAED);
			while (payAED < priceAED){
				scanf(" %f", &inputAED);
				payAED += inputAED;
				printf("\nYou have inserted $%.2f\n$%.2f left: ", payAED, priceAED - payAED);
			}
			printf("\n\nYou have paid your order!\n\n");
			sleep(3);
			if(payAED > priceAED){
				printf("Printing your change (%.2f) ...", payAED - priceAED);
				sleep(2);
			}
			break;
	  }
	}
		break;
	case 2:
		printf("Admin mode menu.\n");
		break;
  }
}
}