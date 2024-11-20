#include <stdio.h>
#include<stdbool.h>
bool convText2Bin (FILE *tfp, FILE * bfp);
#define BLKSIZE 4

//change the number of values in the report.txt

int main()
{
  FILE *tfp,*bfp;
  tfp=fopen("report.txt","r");
   if(tfp==NULL)
  {
       printf(" text file stream was not created");
      return -1;
  }
  
    bfp=fopen("report.bin","wb");
   if(bfp==NULL)
  {
      printf(" binary file stream was not created");
      return -1;
  }
  

  if(convText2Bin (tfp, bfp))
  {
      printf("Text2Bin Conversion: Success");
  }
  else
    fprintf(stderr, "Text2Bin Conversion: (Partial?) Fail");
  
  fclose(bfp);
  
   
   bfp=fopen("report.bin","rb");
   if(bfp==NULL)
  {
      printf(" binary file stream was not created");
      return -1;
  }
  
    float data[BLKSIZE];
    float sum;
    int status;
    while( (status=fread(data,sizeof(float), BLKSIZE,bfp))==BLKSIZE)
       {
         printf("\n%d", status); // DEBUGGING ONLY
	sum=0.0;
           
        for(int i=0; i<BLKSIZE;i++)
         sum+=data[i];    
         
         sum/= BLKSIZE;
         printf("\n the average of this file block of %d elments is %.2f ",BLKSIZE, sum); 
         
     
        }
   
   printf("\nstatus= %d",status);
  if(ferror(bfp)) printf("\n >>>>>>>>>>Hw Failure while processing the finary file");
  if((!feof(bfp))|| (status !=0) ) printf("\n >>>>>>>>Not all the data was read");


 

 fclose(tfp);
 fclose(bfp);
 getchar();

}

bool convText2Bin (FILE *tfp, FILE * bfp){
  float data;
  while(fscanf(tfp,"%f",&data)==1)
  fwrite(&data,sizeof(float), 1,bfp);
  
  if(!feof(tfp)) return false;
  if(ferror(tfp)) return false;
  return true;
}

