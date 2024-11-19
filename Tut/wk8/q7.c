#include <stdio.h>

void silly(int *x);

int main(void){
int x, y;
x = 10; y = 11;
silly(&x);
printf("%d %d\n", x, y);
silly(&y);
printf("%d %d\n", x, y);
}

void silly(int *x){
	int y;
	y = *x + 2;
	*x = 2 * *x;
}
