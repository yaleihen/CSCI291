#include <stdio.h>
#include<stdbool.h>

typedef struct
{
char	level; 
int	code;
}element_t;


int main()
{
  FILE *bfp;
  bfp=fopen("report.bin","wb+");
   if(bfp==NULL)
  {
       printf(" text file stream was not created");
      return -1;
  }
  
  element_t  record, alias;
  
    // write the following record into the binary file, then read it
   record.level='Z';
   record.code=123;
   
   if(fwrite(&record,sizeof(element_t),1,bfp)!=1)
      printf("\n Unsuccessful read operation ");
      else
      printf("\n successful write operation");
   
   // reset the cursor to the start of the file.
    rewind(bfp);
    
    if(fread(&alias,sizeof(element_t),1,bfp)!=1)
      printf("\n Unsuccessful read operation");
      else
      printf("\n %c %d", alias.level, alias.code);


 fclose(bfp);
 getchar();
}



