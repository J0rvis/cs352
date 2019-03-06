#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void displayInt(int theI);


 typedef unsigned int u_int32;
 typedef unsigned long int u_int64;

int main(){
 u_int32 x, y;
 u_int64 z;
 x = 81; y = -65;
 z = x + y;
  /* code snippet goes here: check whether there is an overflow in z. If overflow exists, print message:
  * “There is an overflow bit”. Otherwise, print “No overflow.
  *  */

	if(z&0xffff0000){// each hex f = 1111 in binary 
	 printf("There is overflow%n");
	} else {
	 printf("There is no overflow%n");
	}
}

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

