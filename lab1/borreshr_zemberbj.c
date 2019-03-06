/*=============================================================================*|
 *|   Assignment:  CS 352 LAB1: CODE GENERATION AND FILE VALIDATION            *|
 *|									       *|
 *|       Author:  HANNAH BORRESON and BRENDAN ZEMBER			       *|
 *|     Language:  C COMPILED WITH GCC 					       *|
 *|   To Compile:  gcc -o borreshr_zemberbj borreshr_zemberbj.c		       *|
 *|		   make 						       *|
 *|									       *|
 *|   Instructor:  DR. JACK E TAN					       *|
 *|     Due Date:  10/30/2018						       *|
 *|									       *|
 **===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

typedef unsigned short ushort;
typedef unsigned int uint32;
typedef unsigned long uint64;

/*
 * Parameters: theI
 * Extra method for debugging by displaying binary reps of ints.
 * */
void displayInt(int theI){
 unsigned int temp = theI;
 int i =0;
	for (i = 0; i < 32; i++) {
		if(i %8 == 0){
		 printf(" ");
		}
	 printf("%d",((1 << (31 - i)) & temp) ? 1 :0);
	}
 printf("\n");

}

/*
 * Parameters:	 file = string containing filename
 * 		 count = count of # bytes in a file
 *
 * Description: Cycle through a given file and put it into 32 bit chunks
 * 		using ones complement to add all 32b chunks together
 * 		and return with the total toggled.
 *
 *
 * */

uint32 getCode(char *file, int count){
 //printf("FILENAME = %s \n FILE SIZE = %d\n", file, count);
 FILE *pFile;
 pFile = fopen(file, "r");
	if(pFile == NULL){
	 printf("Invalid File, closing program. \n");
	 exit(1);
	}

 char *buffer = malloc(4 * sizeof(char));
 int arryPlace = 0; 
 uint32 current = 0;
 register uint64 total = 0;

	while(count--){
	 fscanf(pFile,"%c", &buffer[arryPlace]);  
	 current = (current << 8)| buffer[arryPlace];
	 arryPlace++;

	 	if(arryPlace == 4){
		 arryPlace = 0; 
			
		/*Isolate and add overflow if existent */
		 total += current;
		 total = (0x00000000ffffffff & total) + (total >> 32);
		 
		 current = 0; 
		 free(buffer);
		 buffer = malloc(4 * sizeof(char));
		}
	} 

 /* Pad the last few bytes */
	if(arryPlace != 0){
	 current = current << 8 * (4 - arryPlace);
	 total += current;
 	 total = (0x000000000ffffffff & total) + (total >>32);
	} 

 fclose(pFile);
 free(buffer);

 total = ~total;
 return total;
}

bool testValidity(char *newfile, uint32 someCode){
 FILE *pFile;
 pFile = fopen(newfile, "r");
	if(pFile == NULL){
	 printf("Invalid File, closing program. \n");
	 exit(1);
	}

 fseek(pFile, 0L, SEEK_END);
 int count = ftell(pFile);
 fclose(pFile);
 return ((~getCode(newfile, count)) + someCode) == -1;
}


int main(){
 char moreFiles = 'y';

 printf("\nEnter filename: ");
 char filename [20];
 scanf("%s", filename);
 
 FILE *pFile;
 pFile  = fopen(filename,"r");
	if(pFile == NULL){
	 printf("Invalid File, closing program. \n");
	 exit(1);
	}

 fseek(pFile, 0L, SEEK_END);
 int count = ftell(pFile);
 fclose(pFile);

 uint64 code = getCode(filename, count);
 uint32 codePrint = code;
 printf("Calculated code: %08x (in hex)\n", codePrint);

	while(moreFiles == 'y'){
	 printf("Enter another filename for validation: ");
	 char validateFile[20];
	 scanf("%s", validateFile);
	 bool validate = testValidity(validateFile,code);
		if(validate){
		 printf("Validation: Success! They have the same contents");
		} else {
		 printf("Validation: Fail → files have different contents");
		}
	 printf("\nAgain? ");
	 scanf("%s", &moreFiles);
	 moreFiles = tolower(moreFiles);
	}

 return 0;

}
