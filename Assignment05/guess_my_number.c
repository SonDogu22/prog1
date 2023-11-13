#include "base.h" // prog1lib

int main(void){
    int randomNumber = i_rnd(101);
    printf("Please take your Guess!\n");
    bool gameActive = true;

    while (gameActive)
    {
        int input = i_input();

        if (input > randomNumber)
        {
            printf("Too High\n");
        }

        if (input < randomNumber)
        {
            printf("Too Small\n");
        }

        if (input == randomNumber)
        {
            printf("Match!\n");
            gameActive = false;
        }

    }
    
}