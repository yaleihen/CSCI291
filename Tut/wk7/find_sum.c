#include<stdio.h>
int iter_sum(int n);
int recu_sum(int n);
int main(){
    int n=3;
    printf("%d\n", iter_sum(n));
     printf("%d\n", recu_sum(n));
    
}

int recu_sum(int n){
    //design S.C n==1; retur 1
    // g. recu_sum(n)=recu_sum(n-1)+n
    if (n<1) return -1;
    if(n==1) return 1;
    else
    return(recu_sum(n-1)+n);
}

int iter_sum(int n){
    if (n<1) return -1;
    int acc=0;
    for (int i=1; i<=n;i++)
      acc+=i;
      
    return acc;      
}