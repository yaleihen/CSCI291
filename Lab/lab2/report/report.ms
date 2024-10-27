.nr VS 15p
.fam Verdana
.PDFPIC -C "logo.pdf" 3i 3i
.PDFPIC -C "coffeemachine.pdf" 5i 5i
.TL
Coffee Machine Interface in C
.AU
Muthana Al-Sirhan, #8785995
.AI
University of Wollongong in Dubai
CSCI291, Lab #2 Report
.PP

.XS 3
Lab Objective, Methodology
.XA 4
Main Menu
.XA 5
Ordering Coffee (Flowchart)
.XA 6
Ordering Coffee (Order Process)
.XA 7
Ordering Coffee (Payment Process)
.XA 8
Admin Mode (Flowchart)
.XA 9
Admin Mode (Display Quantities)
.XA 10
Admin Mode (Replenishing Ingredients)
.XA 11
Admin Mode (Changing Prices)
.XA 12
Admin Mode (Reset & Collect Sales)
.XE

.PX

.bp \" Page 2

.NH 1
Lab Objective, Methodology
.PP

Self service Coffee Machines are a commodity in all kinds of areas including universities, convenience stores and outside in general. The aim of this lab is to program an interface for a hypothetical self-service Coffee Machine that can serve cups of Espresso, Cappuccino and Mocha, in the C programming language. It should allow customers to order their coffee cup(s) of choice and its operators to display/replenish ingredients, collect total sales and change the price for the aforementioned coffee types. There are a few design limitations applied to the code, such as the inability to implement any arrays, pointers or C-structs.

To implement all this functionality into the C program, constants are defined after:-

.IP \(bu
The price and ingredient requirements for a cup of each coffee type (Table 1)
.IP \(bu
The Low Threshold Quantity for each ingredient in the machine. When an ingredient passes that threshold, a message is displayed instructing the customer to contact an on-site machine operator.
.IP \(bu
A real-value variable which gives the total sales amount,
.fam JetBrains
.B "salesAED"
.fam Verdana
in this case.

.PP
Then, functions are prototyped and defined to act as the front-end and back-end of the interface, examples including:-

.IP \(bu
Menus embedded within infinite while loops, allowing users to navigate the interface
.IP \(bu
Ordering coffee and inserting money
.IP \(bu
An Admin Mode (password required) to display/replenish coffee ingredients and change coffee price.

.TS
allbox expand tab(|);
c s s s s s
c c c c c c.
Table 1: Coffee Type Cup: Ingredients & Prices
Coffee Type | Coffee Beans (g) | Water (mL) | Milk (mL) | Choc. Syrup (mL) | Price (AED)
Espresso | 8 | 30 | - | - | 3.5
Cappuccino | 8 | 30 | 70 | - | 4.5
Mocha | 8 | 39 | 160 | 30 | 5.5
.TE

.PP
Flowcharts have been designed after the aforementioned functions to streamline the programming process (included further in this report).

.bp \"Page 3

.NH 1
Main Menu [main()]

.PP
The main function in this code displays (or "prints") the main menu interface embedded within an infinite while loop. Then, it scans the users integer input corresponding to their desired menu choice. The input is passed to a switch statement with the following cases:

.IP \(bu
1. Coffee Ordering Menu [calls orderCoffee()]
.IP \(bu
2. Admin Mode [calls adminMode()]
.IP \(bu
0. Quitting the Program [returns 0 to the inf. loop]

And a default case for any other input, which prints "INVALID OPTION".
.PDFPIC -C "main.pdf" 3i 3i
.PDFPIC -C "diagramsnew/func_main.pdf" 4i 4i

.bp \" Page 4

.NH 1
Ordering Coffee [orderCoffee()]

.PP
Customers can order coffee through the menu invoked by the orderCoffee() function. During the process, a small list of the final order is always displayed to the customer along with the final price.

.PDFPIC "diagramsnew/func_coffee.pdf" 7i 7i

.bp \" Page 5

.NH 2
Order process
.PP
Each cup ordered calls a function that depletes ingredients and adds to the total order price, depending on the type of coffee ordered.

.PDFPIC "coffee1.pdf" 5i 5i

.PP
Conditional statements are implemented to check if an ingredient(s) has passed the low threshold amount and to print a message instructing to contact an on-site machine operator to replenish the ingredients.

.PDFPIC "coffee3.pdf" 5i 5i

.bp \" Page 6
.NH 2
Payment process
.PP 
When a customer has finished and confirmed the order, it can be paid with:-

.IP \(bu
20, 10, 5 AED notes
.IP \(bu
1, 0.5, 0.25 AED coins

.PP
The remaining change is deposited by the machine.

.PDFPIC "coffee2.pdf" 6i 6i
.bp \" Page 7
.NH 1
Operating The Machine [adminMode()]

.PP
Operators can log into the interface's "Admin Mode" with the password (27341 in this case). In Admin Mode, various functionality is provided to the operator as follows:-

.IP \(bu
Displaying ingredient quantities and total sales
.IP \(bu
Replenishing ingredients
.IP \(bu
Changing the price of a coffee cup
.IP \(bu
Resetting and collecting sales

.PDFPIC "diagramsnew/func_admin.pdf" 6i 6i
.bp \" Page 8
.NH 2
Display all quantities
.PP
Simply prints the quantities of all the ingredients alongside
.fam JetBrains
.ft B
salesAED
.fam Verdana
.ft R
.PDFPIC "admin1.pdf" 5i 5i

.bp \" Page 9
.NH 2
Replenishing Ingredients
.PP
With the use of the 
.fam JetBrains
.B "rand()"
.fam Verdana
function provided by the <stdlib.h> header, random integers from 0 to 32,767 can be generated [1]. To ensure that it generates reasonable numbers for our coffee ingredients, we can specify a range [min, max] with the following "formula":-

.fam JetBrains
.B 
.ce
ingredient = (rand() % (max-min)) + min
.fam Verdana
.ft R
.FS [1]
https://mathbits.com/MathBits/CompSci/LibraryFunc/rand.htm
.FE
.PDFPIC "admin2.pdf" 5i 5i

.PP
One case for resetting the ingredient variables to 0 was implemented for quick testing to ensure no orders can be placed when there are insufficient ingredients.
.PDFPIC "coffee3.pdf" 4i 4i
.bp \" Page 10
.NH 2
Changing Coffee Price
.PP
The operator is prompted to input a new price for the chosen cup. Only positive floats/integers are allowed, otherwise the new price isn't implemented.
.PDFPIC "admin3.pdf" 4i 4i
.PDFPIC "coffee4.pdf" 4i 4i
.bp \" Page 11
.NH 2
Reset & Collect Sales
.PP
The operator can reset the total sale variable by the end of a business day and collect the sales, dispensed by the machine.
.PDFPIC "admin4.pdf" 6i 6i
