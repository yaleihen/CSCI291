#include <stdio.h>

int main(){
    // pointer to input/output files
    
    FILE *inFile;
    FILE *outFile;

    // values for fprintf and fscanf operations 
    
    float nextValue;  /* value to scan from in and write to out */

    // prepare files for input/output
    
    inFile = fopen("data.txt", "r");
    if (inFile == NULL) {
        printf("Text file stream failed"); return -1;
    }
    
    outFile = fopen("dataOut.txt", "w");
    if (outFile == NULL){
        printf("Output file stream failed"); return -2;
    } 

    /* while loop to scan each element in inFile and print to outFile fscanf.
     * returns '1' if it succeeds in scanning one float, otherwise it returns
     * '0'. "fscanfStatus" variable is compared with the returned value. */

    int fscanfStatus = fscanf(inFile, "%f", &nextValue);

    do {

        if (fscanfStatus == 1)
            fprintf(outFile, "%.1f\n", nextValue);
        
        else {
            fseek(inFile, 1, SEEK_CUR);
            printf("Invalid float\n");
        }
        
        fscanfStatus = fscanf(inFile, "%f", &nextValue);
    
    } while ( !(feof(inFile)) );

    if (ferror(inFile)) {
        printf("Hardware failure");
        return -2;
    }

    // close the files
    fclose(inFile);
    fclose(outFile);

    return 0;
}
