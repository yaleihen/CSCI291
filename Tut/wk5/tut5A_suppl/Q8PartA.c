
#include <stdio.h>
#define SIZE 4
int find_index_low(int array[], int length);
int main()
{ 
   
    int data[]={50,30,20,10};
    int index=find_index_low(data, SIZE);
    printf("the index of the lowest value is %d ",index );
    
}
int find_index_low(int array[], int length){
    if (length==0) return -1;
    int min=array[0];
    int index=0;
    for(int i=0;i<length; i++){
        if (array[i]<min){
            min=array[i];
            index=i;
        }
        
    }
    return  index;
}