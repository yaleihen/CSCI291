#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
float salesAED = 0.00;

int espressCount;
int espressTotal;
int cappuCount;
int cappuTotal;
int mochaCount;
int mochaTotal;

int menu();
int orderCoffee();
int adminMode();

int menuSelect;

int main(){

  while (1){
	  printf("Coffee Maker Interface\n 1. Order coffee\n 2. ADMIN MODE (for operators)\n 0. Exit\n");
  scanf("%d", &menuSelect);
  // Switch statement
  switch (menuSelect){
          case 1:
                        orderCoffee();
                        break;
          case 2:
                        adminMode();
                        break;
          case 0:
                        return 0;
          default:
          printf("\nInvalid option. Make sure to input the corresponding number of your desired choice.\n\n");}
  }
  }

int orderCoffee(){
int coffeeChoice;
	while(1){
	printf("Pick your coffee cup of choice!\n");
	if (coffeeBeansg >= beansLowg && watermL >= waterLowmL)
		printf("1. Espresso\n");
	else
		printf("1. Espresso (unavailable)\n");
	if (coffeeBeansg >= beansLowg && watermL >= waterLowmL && milkmL >= milkLowmL)
		printf("2. Cappuccino\n");
	else
		printf("2. Cappuccino (unavailable)\n");
	if (coffeeBeansg >= beansLowg && watermL >= waterLowmL && milkmL >= milkLowmL && chocSyrup >= chocLowmL)
		printf("3. Mocha\n");
	else
		printf("3. Mocha (unavailable)\n");
	printf("9. Confirm order and buy\n");
	printf("0. Exit this menu\n");
	scanf("%d", &coffeeChoice);
	  switch (coffeeChoice){
		case 1:
			if (coffeeBeansg >= 8 && watermL >= espressWatermL){
				printf("How many Espressos would you like to order? ");
				scanf("%d", &espressCount);
				espressTotal += espressCount;
				coffeeBeansg -= (espressCount * beansg);
				watermL -= (espressCount * espressWatermL);
				priceAED += (espressCount * espressPriceAED);
				salesAED += priceAED;
				printf("\nYour order costs $%.2f\n\n", priceAED);
			}
			else{
				printf("\nOption unavailable due to limited ingredients\n\n");
			}
			break;
		case 2:
			if (coffeeBeansg >= 8 && watermL >= cappuWatermL && milkmL >= cappuMilkmL){
				printf("How many Cappuccinos would you like to order? ");
				scanf("%d", &cappuCount);
				cappuTotal += cappuCount;
				coffeeBeansg -= (cappuCount * beansg);
				watermL -= (cappuCount * cappuWatermL);
				milkmL -= (cappuCount * cappuMilkmL);
				priceAED += (cappuCount * cappuPriceAED);
				salesAED += priceAED;
				printf("\nYour order costs $%.2f\n\n", priceAED);
				}
			else{
				printf("\nOption unavailable due to limited ingredients\n\n");
			}
			break;
		case 3:
			if (coffeeBeansg >= 8 && watermL >= mochaWatermL && milkmL >= mochaMilkmL && chocSyrup >= mochaChocmL){
				printf("How many Mochas would you like to order? ");
				scanf("%d", &mochaCount);
				mochaTotal += mochaCount;
				coffeeBeansg -= (mochaCount * beansg);
				watermL -= (mochaCount * mochaWatermL);
				milkmL -= (mochaCount * mochaMilkmL);
				chocSyrup -= (mochaCount * mochaChocmL);
				priceAED += (mochaCount * mochaPriceAED);
				salesAED += priceAED;
				printf("\nYour order costs $%.2f\n\n", priceAED);
				}
			else{
				printf("\nOption unavailable due to limited ingredients\n\n");
			}
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
				printf("Printing your change (%.2f) ...\n", payAED - priceAED);
				sleep(2);
			}
		case 0:
			return 0;
		}
		}
		return 0;
		}

		int adminMode(){
		printf("Input the Admin Password: ");
		int pass;
		scanf("%d", &pass);
		if (pass == adminPasswd){
		int adminMenuSelect;
		printf("\nWelcome to the Admin Menu\n\n");
		while(1){
		printf("1. Display ingredient quantities and total sales\n");
		printf("2. Replenish ingredients\n");
		printf("3. Change coffee price\n");
		printf("0. Exit Admin Mode\n");
		scanf("%d", &adminMenuSelect);
		switch(adminMenuSelect){
			case 1:
				printf("Quantities of coffee ingredients:-\n");
				printf("Coffee Beans (g)\t%d\n", coffeeBeansg);
				printf("Water (mL)\t\t%d\n", watermL);
				printf("Milk (mL)\t\t%d\n", milkmL);
				printf("Choc. Syrup (mL)\t%d\n", chocSyrup);
				printf("\nTotal Coffee Sales: %.2f AED\n\n", salesAED);
				break;
			case 2:
				while(1){
					int replenishChoice;
					printf("\n1. Replenish Beans\n");
					printf("2. Replenish Water\n");
					printf("3. Replenish Milk\n");
					printf("4. Replenish Choc. Syrup\n");
					printf("0. Exit this menu\n");
					scanf(" %d", &replenishChoice);
					switch(replenishChoice){
						case 1:
							while(coffeeBeansg < 150 && coffeeBeansg > 200){
								coffeeBeansg = rand() % 200 + 1;
							}
							break;
						case 0:
							return 0;
						default:
							printf("\nInvalid option. Make sure to input the corresponding number of your desired choice.\n\n");
					}
				}
				break;
			case 0:
				return 0;
				break;
			default: 
				printf("\nInvalid option. Make sure to input the corresponding number of your desired choice.\n\n");
		}
		}
		}
		else
		printf("\nIncorrect Password\n\n");
	}
