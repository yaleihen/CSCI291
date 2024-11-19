#include <stdio.h>

int main()
{
    char ch;
    int total=0;
    
  FILE *fp;
  fp=fopen("report.txt","r");
   if(fp==NULL)
  {
      // LINK Not created
      printf(" file stream was not created");
      return -1;
  }
   while(fscanf(fp,"%c", &ch)==1){
       printf("%c ", ch);
       total++;
   }
   
   if(feof(fp))
   printf("\n the number of chars in the file %d", total);
   else
   printf("EOF was not reached!?");
    
    if(ferror(fp))
      printf(" HARDWARE FAILURE ");
    
   fclose(fp);
   
   getchar();
   return 0;
}
