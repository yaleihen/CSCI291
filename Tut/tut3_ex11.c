#include <stdio.h>
	#define PI 3.14159265
	
	float circle_area(float radius);
	float square_area(float side);
	
   int	main(void)
	{
	      char type;		/* Type of shape. */
	      double  area, dimension;
          
	 /* Display menu and get the type of shape to compute the area. */
	      printf("Enter a:\n");
	      printf("   c -- To compute the area of a circle.\n");
	      printf("   s -- To compute the area of a square.\n");
	      printf("Select> ");
	      scanf("%c", &type);
	      
	      switch(type){
	          case 'c'             :     // empty so the next statements will execute
	          case 'C'             : printf("Enter radius> ");
	                               scanf("%lf", &dimension);
	                               printf("The area of the circle is %.4f\n", circle_area(dimension));
	                               break;
	          case  's'            :     // empty so the next statements will execute       
	          case 'S'             : printf("Enter side length> ");
	                               scanf("%lf", &dimension);
	                               printf("The area of the circle is %.4f\n", square_area(dimension));
	                               break;
	          default: puts("wrong shape selection....");
	          
	      }

	      return 0;
	}

float circle_area(float radius){
    float area;
    area = PI * radius * radius;
    return area;
}

float square_area(float side){
    float area;
    area = side * side;
    return area;
}