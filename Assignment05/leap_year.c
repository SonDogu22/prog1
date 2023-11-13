#include "base.h" // prog1lib

int number_of_days(int year){
   if (year % 4 == 0 && year % 100!= 0){
    if (year%400 != 0)
        {
        return 366; } 
            else{
                return 365;
            }
        }
   else{
      return 365;
   }
}

void test_number_of_days(void){
    test_equal_i(number_of_days(2023),365);
    test_equal_i(number_of_days(2022),365);
    test_equal_i(number_of_days(2021),365);
    test_equal_i(number_of_days(2020),366);
}

int main(voic){
    test_number_of_days();
    return 0;
}