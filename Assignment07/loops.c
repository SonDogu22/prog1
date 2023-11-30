/*
Compile: make loops
Run: ./loops
make loops && ./loops
*/

#include "base.h"

void loops_a(int n) {
    // todo: implement
    int x = 0;
	int y = 1;
	
	for(y = 1; y <= n; y++){
		printf("\n");
		for(x = 1; x <= y; x++){
			printf("%d", x);
		}
	}
	printf("\n");
}

void loops_b(int n) {
    // todo: implement
    
    int x;
	int y;
    int z;
	
     printf ("\n");
    for (y = 1; y <= n; y++){  
        for (x = y; x < n; x++){   //printed so viele leerzeichen wie viel übrig ist bis n. x = 0 also n - 0 = x
            printf(" ") ;                    //printed also x-viele leerzeichen.    
        }  
        for (z = 1; z <= y; z++){ //printed Zahlen bis es so groß ist wie y. Die schleife wird immerwieder ausgelößt,
            printf("%d", z);     // bis die erste schleife (y-schleife) gesättigt(?) ist.   
            }                    //Leerzeichen nach "%d" (Zufällig gefunden, beim debuggen von loops_b
        printf ("\n");   
    }  
}

void loops_c(int n) {
    // todo: implement
     int x;
	int y;
    int z;


        printf ("\n");
        for (y = 1; y <= n; y++){  
            for (x = y; x < n; x++){   //printed so viele leerzeichen wie viel übrig ist bis n. x = 0 also n - 0 = x
                printf(" ");                     //printed also x-viele leerzeichen.    
            }  
            for (z = 1; z <= y; z++){ //printed Zahlen bis es so groß ist wie y. Die schleife wird immerwieder ausgelößt,
                printf("%d ", z);     // bis die erste schleife (y-schleife) gesättigt(?) ist.   
            }                    //Leerzeichen nach "%d" (Zufällig gefunden, beim debuggen von loops_b
        printf ("\n");   
    }  
}

void loops_d(int n) {
    // todo: implement
     int x;
    int y;


    printf("\n");
    for(x = 0; x <= n; x++){//Erste Hälfte
        for(y = 0; y < x; y++){//Printed die leerzeichen links von den Zahlen
            printf(" ");
        }
        printf("%d", x);
        for(y = 1; y <= ((n - x) * 2 - 1); y++){//printed die mitte des Symbols
            printf(" ");
        }
        if(x != n){ //damit in der mitte keine 99 bzw doppelt zahlen passieren
            printf("%d", x);//}
        printf("\n");
        }
    }
/*--------------------------------------------------------------------------------*/
    printf("\n");
    for(x = n - 1; x >= 0; x--){// n - 1, da wir mit einer zahl weniger anfangen müssen z.B. n = 5, 5 wäre in der mitte und die zahl danach müsste 4
        for(y = 0; y < x; y++){//Printed die leerzeichen links von den Zahlen
            printf(" ");
        }
        printf("%d", x);
        for(y = 1; y <= ((n - x ) * 2 - 1); y++){//Printed die leere mitte
            printf(" ");
        }
        printf("%d", x);
        printf("\n");
    }

}


void loops_e(int n){
    int  o = 0;
    int c = n;

    if(n>= 3){


            for(int j = 1; j < n + 2 ; j++){
                printf(" ");
            }

            printf("+");
            for (int y = 0; y < n - 2; y++)
            {
                printf("-");
            }
            printf("+\n");
            
            for (int y = 1; y <= n; y++)
            {   
                for (int i = 1; i <=n - y; i++)
                {

                    printf("-");
            
                }
                
                printf("/");
                
                for (int i = 1; i <= n; i++)
                {
                    printf(" ");
                }
                
                printf("/\n"); 
            }

            printf("+");

            for (int y = 0; y < n - 2; y++)
            {
                printf("-");
            }
            printf("+\n");
        
    }
}



// todo: implement helper functions for loops_f (recommended)

void loops_f(int n) {
    // todo: implement
}

int main(void) {
    loops_a(5);
    loops_b(5);
    loops_c(5);
    loops_d(5);
    loops_a(9);
    loops_b(9);
    loops_c(9);
    loops_d(9);
    loops_e(3);
    loops_e(4);
    loops_e(5);
    loops_e(9);
    loops_e(12);
    loops_f(5);
    loops_f(9);
    return 0;
}
