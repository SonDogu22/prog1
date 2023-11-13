
#include "base.h"


int f(int i){
	 printf("called f\n"); 
	 if (i < 0){

		 return -i;

	 }else {
	
		 return 3 * i;
	
	 }
 }


int main(void){
    test_equal_i(f(2),6 );
    test_equal_i(f(3),9 );
    test_equal_i(f(4),12 );
    test_equal_i(f(5),15 );
    test_equal_i(f(-1),1 );
}