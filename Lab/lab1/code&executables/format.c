   #include <stdio.h>		/* give access to the stdio.h library */
         int main(void)
	{
		printf("%d\n", 455);			/*%d format in print f prints an integer */
		printf("%i\n", 455);            /*i same as d in print f*/
		printf("%d\n", +455);           /*the plus isn't printed, '+' needs to be in format*/
		printf("%d\n\n\n", -455);		/*3 empty lines are created after -455*/
		
		printf("%e\n", 1234567.89);		/*%e prints a floating point number in exponent format */
		printf("%f\n\n\n", 1234567.89); /*%f prints a floating point number to six decimals by default*/

		printf("%c\n", 'A');			/*%c prints a single character, in this case 'A' */
		printf("%s\n\n\n", "This is a string"); /*%s takes the next argument "This is a string" and prints it as a string*/

		printf("%4d\n" , 1);			/*'4' in %4d tells printf to*/
		printf("%4d\n" , 12);			/*print the value in a width of*/
		printf("%4d\n\n\n" , 123);		/*4 spaces*/

        printf("%4d\n" , -1);			/*same thing happens in this output*/
		printf("%4d\n" , -12);			/*only that the negative symbol*/
		printf("%4d\n\n\n" , -123);		/*also takes a space*/


	    printf(" %.4d\n%.9d\n" , 873, 873); /*'.4d' tells printf to print the first integer 873 in a minimum of 4 digits*/
											/*'.9d' does the same to the second value but in 9 digits*/

		printf(" %.3f\n%.6f\n\n\n\ ", 123.94536, 123.94536); /*'.3f' prints the first value as a floating point number with 3 decimal places*/
															 /*'.6f' does the same but in 6 decimal places*/

    	printf("%10s%10d%10c%10f\n\n" , "hello", 7, 'a' , 1.23); /*prints a string, integer, character and floating number in 10 spaces*/
        printf("%-10s%-10d%-10c%-10f\n\n\n" , "hello",7, 'a' , 1.23); /*same but left-justified within the same width*/


	    printf("%d\n\t%d\n" , 786, -786); /*/t makes it so there's an indent in the following line preceding the value*/
        printf("%+d\n\t%+d\n" , 786, -786); /*does the same but '+d' precedes the positive value with a '+'*/

}
