#include <stdio.h>
#define SIZE 5
int sum_oddVal_array(const int array[], int length);
int main()
{ 
    int data[]={11,2,13,4,15};
    printf("data is at address : %p\n", data);
    int sum;
    sum=sum_oddVal_array(data,SIZE);
    printf("sum is %d", sum);
    return 0;
}

int sum_oddVal_array(const int array[], int length){
 printf("array is at address: %p\n", array)    ;
 int sum=0;
 for(int i=0;i<length;i++){
     if(array[i]%2!=0)
       sum+=array[i];
 }
 return sum;
}

