#include <stdio.h>
#include <stdbool.h>

// size of original 1D array
#define SIZE 12
#define nRows 3
#define nCols 4

// prototypes
bool is_valid(const int array[], int length, int pos);
void insert_element(int array[], int length, int pos, int value);
void remove_element(int array[], int length, int pos);
void reshape(int array[], int length, int rows, int cols, int matrix[][nCols]);
void trans_matrix(int rows, int cols, int matrix[][nCols], int matrixTransp[][nRows]);
bool found_duplicate(int array[], int length);

// main loop
int main(void){
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int matrix[nRows][nCols];
    // transpose of a matrix reverses rows and columns
    int matrixTransp[nCols][nRows];
    printf("Original array:- \n");
    for (int i = 0;  i < SIZE; i++){
        printf("%d ", array[i]);
    }
    int value, pos; // values for array transformation function inputs
    while(1){
    printf("\n\nHow would you like to transform this array?\n"
            "1. Insert an element\n"
            "2. Remove an element\n"
            "3. Reshape into matrix\n"
            "4. Transpose matrix (execute 3 first)\n"
            "Select your choice: ");
    int menuChoice;
    scanf("%d", &menuChoice);
    switch(menuChoice){
        case 1:
            printf("Input the desired value and position of the element (value position): ");
            scanf("%d%d", &value, &pos);
            insert_element(array, SIZE, pos, value);
            break;
        case 2:
            printf("Input the element you wish to remove (position): ");
            scanf("%d", &pos);
            remove_element(array, SIZE, pos);
            break;
        case 3:
            reshape(array, SIZE, nRows, nCols, matrix);
            break;
        case 4:
            trans_matrix(nRows, nCols, matrix, matrixTransp);
            break;
        case 0:
            return 0;
            break;
        default:
            printf("Invalid option\n");
            break;
    }
    }
}

/* function for checking position validity
 * "pos" index can't be equal to or greater than "length" */

bool is_valid(int array[], int length, int pos){
    if (pos >= length)
        return false;
    else
        return true;
}

// function for inserting an element at a specified position
void insert_element(int array[], int length, int pos, int value){
    int changedArray[length + 1];
    // checks validity of "pos" first
    if (is_valid(array, length, pos)){
        // new array to store transformed array
        int j = 0; // for indexing the original array
        // transformed array is the same up until "pos" element
        for (int i = 0; i <= length; i++){
            changedArray [i] = array[j];
            j++;
            // "value" is inserted at pos and j is adjusted accordingly
            if (i == pos){
                changedArray[i] = value;
                j--;
            }
            printf("%d ", changedArray[i]);
        }
        // checks for duplicates after inserting
        if (found_duplicate(changedArray, length + 1))
            printf("\n'%d' duplicate found", changedArray[pos]);
       
    }
    else
        printf("Position isn't a valid index");
}

// function for removing an element at a specified position
void remove_element(int array[], int length, int pos){
    // new array to store transformed array
    int changedArray[length - 1];
    // checks validity of "pos" first
    if (is_valid(array, length, pos)){
        int j = 0; // for indexing the original array
        for (int i = 0; i < length - 1; i++){
            changedArray[i]=array[j];
            j++;
            // j skips the entry at "pos" of the original array
            if (i == pos)
                j++; 
            printf("%d ", changedArray[i]);
        }
    }
    else
        printf("Position isn't a valid index");
}

// function for finding a duplicate element after inserting
bool found_duplicate(int array[], int length){
    // two for loops to compare each pair of elements
    for (int i = 0; i < length - 1; i++){
        for (int j = i + 1; j < length; j++){
            if (array[i] == array[j])
                return true;
        }
    }
    return false;
}

// function for reshaping a 1D array into a matrix, filling by column
void reshape(int array[], int length, int rows, int cols, int matrix[][nCols]){
    if (length == nRows * nCols){ // length has to be a product of nRows and nCols
        int k = 0; // for indexing the 1D array
        // accessing by rows first means the array is being filled by column
        for (int i = 0; i < nCols; i++){
            printf("Column %d = ", i);
            for (int j = 0; j < nRows; j++){
                matrix[j][i] = array[k++];
                printf("%d ", matrix[j][i]);
            }
            printf("\n");
        }
    }
    else
        printf("1D array cannot be reshaped into matrix\n");
}

// function for generating the transpose of input matrix
void trans_matrix(int rows, int cols, int matrix[][nCols], int matrixTransp[][nRows]){
    for (int i = 0; i < nRows; i++){
        for (int j = 0; j < nCols; j++){
            matrixTransp[j][i] = matrix [i][j];
        }
    }
    for (int i = 0; i < nRows; i++){
        printf("Transpose Column %d = ", i);
        for (int j = 0; j < nCols; j++){
            printf("%d ", matrixTransp[j][i]);
        }
        printf("\n");
    }
}
