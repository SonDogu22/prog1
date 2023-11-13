/*
 * Compile:         make X
 * Run:             ./X
 * Compile and Run: make X && ./X
 */
#include "base.h" // prog1lib

// todo: define constants
    int standardPrice = 100;
    int priceReduction1 = 90;
    int priceReduction2 = 75;
    int noShippingCost = 2000;
    int shippingCost = 1999;
    int costForShipping = 500;
    int noCost = 0;
// todo: write function price
int price(int product){

    int cost = 0;

    if(product <= 0){
		return 0;
	}else if (product < 10){
        cost = product * standardPrice;
    }else if (product < 50 && product >= 10){
        cost = product * priceReduction1;
    }else if (product >= 50){
        cost = product * priceReduction2;
    } 
    
    
    if (cost < shippingCost)
    {
        cost += costForShipping;
    }

    return cost;
}
// todo: write function price_test
void price_test (void) {
	test_equal_i(price(0), 0);
	test_equal_i(price(9), 1400);
	test_equal_i(price(15), 1850);
	test_equal_i(price(23), 2070);
	test_equal_i(price(50), 3750);
	test_equal_i(price(-1), 0);
}


int main(void) {
    // todo: call price_test function
    price_test();
    return 0;

}
