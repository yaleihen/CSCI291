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
  // file stream write only Access!
  bfp=fopen("report.bin","wb");
  
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
    fprintf(stderr, "\n Txt2Bin Conversion:(Partial?)Fail");
    

     fclose(bfp);
   // reopen the file in read access mode   
    bfp=fopen("report.bin","rb");
 
   
   int data;
   while( fread(&data,sizeof(int), 1,bfp)==1)
     printf("\n %d", data);
  
     if(!feof(bfp)) printf("\n The binary file has not been read fully");
	 if(ferror(bfp)) printf("\n Hardware failure while processing the binary file");
  
  
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

