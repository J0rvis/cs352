#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

bool matchdigits(int num, int num2){
	while (num > 0){
	 int n1 = num % 10;
	 int n2 = num2 % 10;
		if(n1 != n2){
		 return false;
		}
		num = num/10;
		num2 = num2/10;
	}
 printf("AUTOMORPHIC: %d\n");
 return true;
}


bool isAutomorphic(int N, int sq){
	while (N > 0) {
		if (N % 10 != sq % 10) 
            	 return false;
	 N /= 10; 
         sq /= 10; 
    	} 

 return true; 
}  

/*
int main(){ 
    int N = 5;
    int sq = N * N;
	if(isAutomorphic(N, sq)){
 	 printf( "Automorphic \n");
	} else {
	 printf("Not Automorphic\n");
	}
  
return 0; 
} 
*/

int main(){
 char yN = 'y';
	while(yN != 'n'){
	 int num = 0;					//num = $s0
	 int AList [100];
	 int TAList [100];
	 int count0 = 0;
	 int count1 = 0;
	
	 printf("Enter a number: \n"); 
	 scanf(" %d", &num);
	 printf("\nYour number is: %d\n", num);
	 int i = 0;					// i = $t1
		for(i = 2; i <= num; i++){
		 int num2 = i * i;			//num2 = $s1
			if(isAutomorphic(i, num2)){	//isAutoBool = $s4
		 	 AList[count0] = i;
			 count0++;	
			} 
			if(isAutomorphic(i, 3 * num2)){
			 TAList[count1] = i;
			 count1++;
			}

		}

	int t = 0;
	printf("A list : \n");
	for(t =0; t < count0; t++){
	 printf(" %d \n", AList[t]);
	}

	printf("\nT list : \n");
	for(t = 0; t < count1; t++){
	 printf(" %d \n", TAList[t]);
	}

	 printf("Again? (enter y or n) : \n");
	 scanf(" %c", &yN);
	}
 return 0;
} 
