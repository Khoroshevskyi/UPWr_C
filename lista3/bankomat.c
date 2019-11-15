#include <stdio.h>
#include <stdlib.h>

const int BANKNOTES[] = {500, 200, 100, 50, 20, 10};
const float COINS[] = {5, 1, 2, 0.50, 0.20, 0.10, 0.5, 0.2, 0.1};

int main(void)
{
    float amount;
    printf("Enter an amount: ");
    scanf("%f", &amount);
    int memory = amount/BANKNOTES[0] + 25;

    int* banknotes_needed;
    float* coins_needed;

    banknotes_needed = calloc( memory, sizeof(int) );
    int banknotes_needed_length = -1;
    int k = 0;
    int i = 0;
    while ( i < (sizeof(BANKNOTES)/sizeof(BANKNOTES[i])))
    {
        k++;
        //if(k>40){break;}
        float amount_new = amount - BANKNOTES[i];
        printf("amount: %f, %f , %i \n", amount_new, amount, BANKNOTES[i]);
        if (amount_new > 0)
        {
            amount = amount_new;
            banknotes_needed_length += 1;
            *(banknotes_needed + banknotes_needed_length) = BANKNOTES[i];

        } else
        {
            i += 1;
        }
    }

    coins_needed = calloc( 25, sizeof(int) );
    int coins_needed_length = -1;

    k = 0;
    i = 0;
    while ( i < (sizeof(COINS)/sizeof(COINS[i])))
    {
        k++;
        //if(k>40){break;}
        float amount_new = amount - COINS[i];
        printf("amount: %f, %f , %i \n", amount_new, amount, BANKNOTES[i]);
        if (amount_new > 0)
        {
            amount = amount_new;
            coins_needed_length += 1;
            *(coins_needed + coins_needed_length) = COINS[i];

        } else
        {
            i += 1;
        }
    }


    // banknotes needed
    int* banknotes_arr[banknotes_needed_length];
    float* coins_arr[coins_needed_length];

    for ( i = 0; i <= banknotes_needed_length; i++ )
       printf("*(p + %d) = %d\n", i, *(banknotes_needed+i) );

    // coins needed
    for ( i = 0; i <= coins_needed_length; i++ )
       printf("*(p + %d) = %.2f  \n", i, *(coins_needed+i) );

    return 0;

}