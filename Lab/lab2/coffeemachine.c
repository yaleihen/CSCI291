///*** Headers ***///

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

/* End of Headers */

///*** Constants ***///

// Admin Password
#define adminPasswd 27341

// Coffee Ingredient(s) constants
#define beansg 8

// for Espresso 
#define espressWatermL 30
float espressPriceAED = 3.5;

// for Cappuccino
#define cappuWatermL 30
#define cappuMilkmL 70
float cappuPriceAED = 4.5;

// for Mocha
#define mochaWatermL 39
#define mochaMilkmL 160
#define mochaChocmL 30
float mochaPriceAED = 5.5;

// Low Threshold Amount for each Ingredient
#define beansLowg 8
#define waterLowmL 39
#define milkLowmL 70
#define chocLowmL 30

/* End of Constants */

///*** Variables ***///

// Quantities of Coffee Ingredients
int coffeeBeansg = 50;
int watermL = 250;
int milkmL = 500;
int chocSyrup = 150;

// Initializing floats for Price, Payment, Change and Sale
float priceAED = 0.00;
float payAED = 0.00;
float inputAED = 0.00;
float salesAED = 0.00;

// Initializing integers for counting how much Coffee of a certain type is ordered
int espressCount;
int cappuCount;
int mochaCount;

// Initializing a char acting as input for y/n prompts
char yesno;

/* End of Variables */

///*** Function Prototypes ***///

// Menu Functions
int orderCoffee();
int adminMode();

// Ordering Coffee Functions
int orderCoffeeEspresso();
int orderCoffeeCappuccino();
int orderCoffeeMocha();
void orderedCoffee();
int buyOrderedCoffee();
void resetOrderSession();
void insertMoney();

// Admin Menu Functions
int replenishIngredients();
int changeCoffeePrice();
void resetSales();
void displaySalesIngredients();
void negativePriceWarn();

/* End of Prototypes */

/* "sleep(x)" is used throughout the program after most
 * "printf" statements to make the coffee machine stop
 * executing code for x seconds, making it "sleep". 
 * output becomes more readable this way. */

///*** Main Function ***///
int main(){
	int menuSelect; // allows user to input their menu of choice
	srand(time(NULL)); // uses the devices internal clock to control the random generation of numbers

	while (1){ // menus embedded within infinite while loop
	  printf("\nCoffee Maker Interface\n\n\t1. Order coffee\n\t2. ADMIN MODE (for operators)\n\t0. Exit\n\n");
	  printf("Input the number corresponding to your choice: ");
	  scanf("%d", &menuSelect); // allows user to input menu choice,
	  switch (menuSelect){ // and passes input to switch case statement
          	case 1:
			orderCoffee(); // ordering coffee menu
			break;
          	case 2:
			adminMode(); // admin mode menu (for operators)
			break;
          	case 0:
			return 0; // returns 0 to the infinite while loop, halting it from repeating
			break;
		default: // any other input returns "INVALID OPTION"
			printf("\nINVALID OPTION\n\n");
			sleep(1);
			break;
  }
  }
  }

int orderCoffee(){ // display the menu to order and buy coffee
int coffeeChoice;
	printf("\nCoffee Ordering Menu\n\n");
	sleep(1);
	while(1){ // menu embedded within infinite while loop
	
	/* The following if else statements check the current quantity
	 * of the coffee ingredients required for each type of coffee. 
	 * If they are below past the "Low Threshold Amount", it prints
	 * a message next to the coffee type stating that it is unavailable
	 * and that an on-site machine operator must be contacted. */

	if (coffeeBeansg >= beansLowg && watermL >= waterLowmL)
		printf("\t1. Espresso ($%.2f)\n", espressPriceAED);
	else
		printf("\t1. Espresso (unavailable, contact on-site operator)\n");
	if (coffeeBeansg >= beansLowg && watermL >= waterLowmL && milkmL >= milkLowmL)
		printf("\t2. Cappuccino ($%.2f)\n", cappuPriceAED);
	else
		printf("\t2. Cappuccino (unavailable, contact on-site operator)\n");
	if (coffeeBeansg >= beansLowg && watermL >= waterLowmL && milkmL >= milkLowmL && chocSyrup >= chocLowmL)
		printf("\t3. Mocha ($%.2f)\n", mochaPriceAED);
	else
		printf("\t3. Mocha (unavailable, contact on-site operator)\n");
	printf("\n\t9. Confirm/cancel order\n");
	printf("\t0. Exit this menu\n\n");
	printf("Pick your coffee type of choice: ");
	scanf("%d", &coffeeChoice); // prompts customer for their desired coffee,
	switch (coffeeChoice){ // passes customer input to switch case statement.
	
	/* inputs 1-3 execute functions that order coffee 
	 * while 9 confirms or cancels the final order */
		
		case 1:
			orderCoffeeEspresso();
			break;
		case 2:
			orderCoffeeCappuccino();
			break;
		case 3:
			orderCoffeeMocha();
			break;
		case 9:
			buyOrderedCoffee();
			break;
		case 0: // customer's current order must be confirmed/cancelled before leaving this menu
			if (priceAED > 0){
				printf("\nConfirm/cancel your current order to leave this menu.\n\n");
				break;
			}
			else{
			return 0;
			break;
			}
		default:
			// for inputs not corresponding to any option
			printf("\nINVALID OPTION\n\n"); // for inputs not corresponding to any option
			sleep(1);
			break;
		}
		}
		return 0;
		}

/* Function for printing the Admin Menu and its
 * functionality for operators with the password */

int adminMode(){

	/* The following lines prompt the operator for the password,
	 * which is an integer. If the password is correct, the operator
	 * receives access to the Admin Menu. Otherwise, no access. */

	printf("Input the Admin Password: ");
	int pass;
	scanf("%d", &pass);
	if (pass == adminPasswd){
	int adminMenuSelect;
	while(1){ // menu embedded within infinite while loop
		printf("\nADMIN MENU\n\n");
		printf("\t1. Display ingredient quantities and total sales\n");
		printf("\t2. Replenish ingredients\n");
		printf("\t3. Change coffee price\n");
		printf("\t4. Reset sale counter and collect the money\n");
		printf("\t0. Exit Admin Mode\n\n");
	  	printf("Input the number corresponding to your choice: ");
		scanf("%d", &adminMenuSelect);
		switch(adminMenuSelect){
			case 1:

			/* inputs 1-4 execute various admin mode functions */
				displaySalesIngredients();
				break;
			case 2:
				replenishIngredients();
				break;
			case 3:
				changeCoffeePrice();
				break;
			case 4:
				resetSales();
				break;
			case 0:
				return 0;
				break;
			default: 
				printf("\nINVALID OPTION\n\n");
				sleep(1);
				break;
		}
		}
	}
		else
		printf("\nIncorrect Password\n\n");
	}

/* The three following functions add a coffee cup to
 * the order and deplete the ingredients accordingly */

int orderCoffeeEspresso(){
	if (coffeeBeansg >= 8 && watermL >= espressWatermL){
		printf("\nAdding an Espresso to your order...\n");
		espressCount += 1;
		coffeeBeansg -= beansg;
		watermL -= espressWatermL;
		priceAED += espressPriceAED;
		sleep(1);
		orderedCoffee();
		sleep(1);
		}
	else{
		printf("\nOption unavailable due to limited ingredients\n\n");
		sleep(1);
	}
}

int orderCoffeeCappuccino(){
	if (coffeeBeansg >= 8 && watermL >= cappuWatermL && milkmL >= cappuMilkmL){
		printf("\nAdding a Cappuccino to your order...\n");
		cappuCount += 1;
		coffeeBeansg -= beansg;
		watermL -= cappuWatermL;
		milkmL -= cappuMilkmL;
		priceAED += cappuPriceAED;
		sleep(1);
		orderedCoffee();
		sleep(1);
		}
	else{
		printf("\nOption unavailable due to limited ingredients\n\n");
		sleep(1);
	}
}

int orderCoffeeMocha(){
	if (coffeeBeansg >= 8 && watermL >= mochaWatermL && milkmL >= mochaMilkmL && chocSyrup >= mochaChocmL){
		printf("\nAdding a Mocha to your order...\n");
		mochaCount += 1;
		coffeeBeansg -= beansg;
		watermL -= mochaWatermL;
		milkmL -= mochaMilkmL;
		chocSyrup -= mochaChocmL;
		priceAED += mochaPriceAED;
		sleep(1);
		orderedCoffee();
		sleep(1);
		}
	else{
		printf("\nOption unavailable due to limited ingredients\n\n");
		sleep(1);
	}
}

/* end of coffee type functions */

// allows customer to buy coffee after confirming their order
int buyOrderedCoffee(){
	if (priceAED > 0){
		orderedCoffee();
		printf("Confirm your order? (y/n) ");
		scanf(" %c", &yesno);
		if (yesno == 'y'){
			insertMoney();
			printf("\nYou have paid your order!\n\n");
			sleep(2);
			if(payAED > priceAED){
				float changeAED = payAED - priceAED;
				printf("Printing your change ($%.2f)...\n", changeAED);
				sleep(2);
			}
			salesAED += priceAED;
			resetOrderSession();
		}
		else if (yesno == 'n'){ 
		// if order is cancelled, ingredients are restored to their previous values
			printf("\nYour order has been cancelled.\n\n");
			coffeeBeansg += ((espressCount + cappuCount + mochaCount) * beansg);
			watermL += ((espressCount * espressWatermL) + (cappuCount * cappuWatermL) + (mochaCount * mochaWatermL));
			milkmL += ((cappuCount * cappuMilkmL) + (mochaCount * mochaMilkmL));
			chocSyrup += (mochaCount * mochaChocmL);
			resetOrderSession();
		}
		else{
			printf("\nINVALID CHOICE\n\n");
			sleep(1);
		}
	}
	else{
	printf("\nYou have not ordered anything.\n");
	}
}

void displaySalesIngredients(){ // displaying sales and ingredient quantity
	printf("\nQuantities of coffee ingredients:-\n");
	printf("Coffee Beans (g)\t%d\n", coffeeBeansg);
	printf("Water (mL)\t\t%d\n", watermL);
	printf("Milk (mL)\t\t%d\n", milkmL);
	printf("Choc. Syrup (mL)\t%d\n", chocSyrup);
	printf("\nTotal Coffee Sales: %.2f AED\n\n", salesAED);
	sleep(2);
}

/* allows operator to replenish ingredients with the use of rand().
 * by default, rand() generates a constant set of random numbers,
 * meaning the number generation is psuedo-random rather than
 * completely random. in line 90, the devices internal clock is
 * used to constantly generate new sets of numbers, effectively
 * implementing a RNG (random number generator) */

int replenishIngredients(){
	int replenishChoice;
	while(1){
	printf("\n\t1. Replenish Beans\n");
	printf("\t2. Replenish Water\n");
	printf("\t3. Replenish Milk\n");
	printf("\t4. Replenish Choc. Syrup\n");
	printf("\t5. Replenish all quantities\n");
	printf("\t7. (FOR TESTING) Deplete all quantities\n");
	printf("\t0. Exit this menu\n\n");
	printf("Input the number corresponding to the ingredient you need to replenish: ");
	scanf("%d", &replenishChoice);
	switch(replenishChoice){
		case 1:
			coffeeBeansg += (rand() % (200 - 150 + 1)) + 150;
			sleep(1);
			printf("\nUpdated quantity of coffee beans to %d (g)\n", coffeeBeansg);
			sleep(2);
			break;
		case 2: 
			watermL += (rand() % (1200 - 1150 + 1)) + 1150;
			sleep(1);
			printf("\nUpdated quantity of water to %d (mL)\n", watermL);
			sleep(2);
			break;
		case 3:
			milkmL += (rand() % (1650 - 1550 + 1)) + 1550;
			sleep(1);
			printf("\nUpdated quantity of milk to %d (mL)\n", milkmL);
			sleep(2);
			break;
		case 4:
			chocSyrup += (rand() % (350 - 300)) + 300;
			sleep(1);
			printf("\nUpdated quantity of chocolate syrup to %d (mL)\n", chocSyrup);
			sleep(2);
			break;
		case 5:
			coffeeBeansg += (rand() % (200 - 150 + 1)) + 150;
			watermL += (rand() % (1200 - 1150 + 1)) + 1150;
			milkmL += (rand() % (1650 - 1550 + 1)) + 1550;
			chocSyrup += (rand() % (350 - 300)) + 300;
			sleep(2);
			printf("\nUpdated quantity of coffee beans to %d (g)\n", coffeeBeansg);
			printf("Updated quantity of water to %d (mL)\n", watermL);
			printf("Updated quantity of milk to %d (mL)\n", milkmL);
			printf("Updated quantity of chocolate syrup to %d (mL)\n", chocSyrup);
			sleep(4);
			break;
		case 7:
			coffeeBeansg = 0;
			watermL = 0;
			milkmL = 0;
			chocSyrup = 0;
			sleep(1);
			printf("\nAll ingredients depleted\n");
			sleep(2);
			break;
		case 0:
			return 0;
		default:
			printf("\nINVALID OPTION\n\n");
			sleep(1);
			break;
	}
	}
}

int changeCoffeePrice(){ // allows the operator to change the price of each coffee type.
	int changePriceSelect;
	float newPrice;
	while(1){
	printf("\nUpdate Coffee Prices\n\n");
	printf("\t1. Change Espresso Price (%.2f)\n", espressPriceAED);
	printf("\t2. Change Cappuccino Price (%.2f)\n", cappuPriceAED);
	printf("\t3. Change Mocha Price (%.2f)\n", mochaPriceAED);
	printf("\t0. Exit this menu\n\n");
	printf("Input the number corresponding to the coffee type: ");
	scanf("%d", &changePriceSelect);
	switch(changePriceSelect){
		case 1:
			printf("\nInput new price for a cup of Espresso (%.2f): ", espressPriceAED);
			scanf("%f", &newPrice);
			if (newPrice > 0){
				espressPriceAED = newPrice;
				printf("\nThe new price for one (1) cup of Espresso is %.2f\n", newPrice);
			}
			else {
				negativePriceWarn();
			}
			break;
		case 2:
			printf("\nInput new price for a cup of Cappuccino (%.2f): ", cappuPriceAED);
			scanf("%f", &newPrice);
			if (newPrice > 0){
				cappuPriceAED = newPrice;
				printf("\nThe new price for one (1) cup of Cappuccino is %.2f\n", newPrice);
			}
			else {
				negativePriceWarn();
			}
			break;
		case 3:
			printf("\nInput new price for a cup of Mocha (%.2f): \n", mochaPriceAED);
			scanf("%f", &newPrice);
			if (newPrice > 0){
				mochaPriceAED = newPrice;
				printf("\nThe new price for one (1) cup of Mocha is %.2f\n", newPrice);
			}
			else {
				negativePriceWarn();
			}
			break;
		case 0:
			return 0;
			break;
		default:
			printf("\nINVALID OPTION\n\n");
			sleep(1);
			break;
	}
	}
}

void orderedCoffee(){ // displays the customers order while ordering and before confirming
	printf("\nYou have ordered:-\n\n");
	if (espressCount > 0){
		printf("\t%d Espresso(s)\n", espressCount);
	}
	if (cappuCount > 0){
		printf("\t%d Cappuccino(s)\n", cappuCount);
	}
	if (mochaCount > 0){
		printf("\t%d Mocha(s)\n", mochaCount);
	}
	printf("\nYour order costs $%.2f\n\n", priceAED);
}

/* allows customer to insert:-
 * (20, 10, 5) AED notes 
 * (1, 0.5, 0.25) AED coins */
void insertMoney(){
	while (payAED < priceAED){
		float remainingAED = priceAED - payAED;
		printf("\nInsert $%.2f in notes/coins: ", remainingAED);
		scanf(" %f", &inputAED);
		if (inputAED == 20 | inputAED == 10 || inputAED == 5 || inputAED == 1 || inputAED == 0.5 || inputAED == 0.25){
			payAED += inputAED;
			if (remainingAED > 0){
				printf("\nYou have inserted $%.2f\n", payAED, remainingAED);
			}
			else{
				printf("\nYou have inserted $%.2f", payAED);
			}
		}
		else{
		printf("Invalid note/coin\n");
		}
	}
	// in case more than enough money has been inserted, change is printed
		sleep(2);
		if(payAED > priceAED){
			float changeAED = payAED - priceAED;
			printf("Printing your change ($%.2f)...\n", changeAED);
			sleep(2);
		}
		salesAED += priceAED;
		resetOrderSession();
}

/* resets all the temporary order variables, such as ones
 * involving money and the cup count of ordered coffee */

void resetOrderSession(){
	priceAED = 0;
	payAED = 0;
	espressCount = 0;
	cappuCount = 0;
	mochaCount = 0;
}

// allows operator to collect money and resets sale counter to 0

void resetSales(){
	salesAED = 0;
	printf("Sale variable has been reset\n");
	sleep(1);
	printf("Dispensing money...\n");
	sleep(2);
}

// message when negative price is inputted while changing cup price

void negativePriceWarn(){
	printf("\nINVALID PRICE\n");
	printf("\nMake sure it is a positive value\n");
	sleep(1);
}
