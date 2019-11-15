#include <stdio.h>
#include <stdlib.h>

const int BANKNOTES[] = {500, 200, 100, 50, 20, 10};
const float COINS[] = {5, 1, 2, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};

int main(void)
{
    double amount;
    printf("Enter an amount: ");
    scanf("%lf", &amount);
    double amount1 = amount;

    int banknotes_needed[(sizeof(BANKNOTES)/sizeof(BANKNOTES[0]))];
    int coins_needed[(sizeof(COINS)/sizeof(COINS[0]))];

    for (int i=0; i<(sizeof(BANKNOTES)/sizeof(BANKNOTES[0])); i++)
    {
        banknotes_needed[i] = 0;
    }
    for (int i=0; i<(sizeof(COINS)/sizeof(COINS[0])); i++)
    {
        coins_needed[i] = 0;
    }


    int i = 0;
    while ( i < (sizeof(BANKNOTES)/sizeof(BANKNOTES[i])))
    {
        double amount_new = amount - BANKNOTES[i];

        if (amount_new >= 0)
        {
            amount = amount_new;
            banknotes_needed[i] += 1;
            //rintf("banknotes_needed[i]: %i , %i \n", banknotes_needed[i], i);
        }
        else
        { i += 1; }
    }

    i = 0;
    while ( i < (sizeof(COINS)/sizeof(COINS[i])))
    {
        double amount_new = amount - COINS[i];
        if (amount_new >= 0)
        {
            amount = amount_new;
            coins_needed[i] += 1;
            //printf("coins_needed[i]: %i , %i \n", coins_needed[i], i);

        } else
        {
            i += 1;
        }
    }
    printf("Liczba poczatkowa: %.2f \n", amount1);

    printf("Potrzebna ilosc banknot: \n");
    for (i = 0; i < (sizeof(BANKNOTES)/sizeof(BANKNOTES[i])); i++)
    {

        if (banknotes_needed[i] != 0)
            printf("Banknota: %i , ilosc: %i \n", (BANKNOTES[i]), banknotes_needed[i]);
    }

    printf("Potrzebna ilosc monet: \n" );
    for (i =0; i < (sizeof(COINS)/sizeof(COINS[i])); i++)
    {
        if (coins_needed[i] != 0)
            printf("Moneta: %.2f , ilosc: %i \n",COINS[i], coins_needed[i]);
    }

}