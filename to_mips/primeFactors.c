#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>

int findPrimes(int num){
 int total = 1;
 printf("\t\t 1\n");
	if(num %2 == 0){
	 printf("\t\t 2\n");
	 total += 2;
	}
 int i = 0; 
 int t = 0;
 int sq = sqrt(num); //put in loop
	for(i = 3; i <= sq; i+=2){ //check possible prime nums
		if( num % i == 0){ //check for factor
			for(t = 3; t <= i; t+=2){ //check for prime
				if ( t == i)  { //no factor then prime
                                  total += i;
                                  printf("\t\t %d\n",i);
                                }

				if(i%t == 0 ){ //if not prime stop
				 break;
				
				}
        	
        		} 
		}
	}
	for(t=3; t <=num; t++){
		if(t == num){
		 total += num;
		 printf("\t\t %d\n", num);
		}
		if(num % t == 0){
		return total;

		}

	}
 return total;
}


int main(){

 int num = findPrimes(7);
 printf("total: %d\n", num);

 return 0;
}


