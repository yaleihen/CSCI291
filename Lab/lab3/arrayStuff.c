#include <stdio.h>
#include <stdbool.h>

#define SIZE 5
#define nRows 3
#define nCols 4

// Prototypes
void printArray(int array[], int length);

int main(){
	int testArray[SIZE] = {10,20,30,40,50};
	printf("Test array:\n");
	printArray(testArray[SIZE], SIZE);
}

void printArray(int array[], int length){
	for (int i = 0; i < length; i++){
		printf("[%d] = %d\n, i, testArray[i]");
	}
}
