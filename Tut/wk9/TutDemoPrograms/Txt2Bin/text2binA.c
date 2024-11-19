#include <stdio.h>
#include<stdbool.h>

// run the file with the attached report.txt file; check the resulting .bin file
// change one integer value in report.txt to a character and run the program again

bool convText2Bin (FILE *tfp, FILE * bfp);

int main()
{
  FILE *tfp,*bfp;
  tfp=fopen("report.txt","r");
  
   if(tfp==NULL)
  {
      // LINK Not created
      printf(" text file stream was not created");
      return -1;
  }
  // file stream read write!
  bfp=fopen("report.bin","wb+");
  
  if(bfp==NULL)
  {
      // LINK Not created
      printf(" binary file stream was not created");
      return -1;
  }
  

  if(convText2Bin (tfp, bfp))
  {
      printf("\n Txt2Bin Conversion: Success");
  }
  else
    fprintf(stderr, "\n Txt2Bin Conversion: (Partial) Fail");
    
   // NOw that I have loaded the binary file, I need to rewind the file cursor
   // to the start to read the file content from the start.
   rewind(bfp);
   
   int data;
   while( fread(&data,sizeof(int), 1,bfp)==1)
     printf("\n %d", data);
  
   fclose(tfp);
   fclose(bfp);
   getchar();
}

bool convText2Bin (FILE *tfp, FILE * bfp){
  int data;
  while(fscanf(tfp,"%d",&data)==1)
  fwrite(&data,sizeof(int), 1,bfp);
  
  if(!feof(tfp)) return false;
  if(ferror(tfp)) return false;
  return true;
}

