#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n_elements;

    printf("Podaj ilosc elementow: ");
    scanf("%d", &n_elements);
    printf( "\nYou entered: %d", n_elements);

    int elementy[n_elements];

    printf("\nPodaj kolejne elementy: ");
    for(int i=0; i<n_elements; i++){
        scanf("%d", &elementy[i]);
    }

    printf("\n You entered: ");
    for (int nr = 0; nr < n_elements; nr ++)
    {
        printf( "%i ", elementy[nr]);
    }

    int dodatnie = 0;
    int ujemne = 0;

    for (int nr = 0; nr < n_elements; nr ++)
    {
        if (elementy[nr] >= 0) {
            dodatnie += elementy[nr];
        }
        else {
            ujemne += elementy[nr];
        }
    }

    printf( "\n suma elementow dodatnich: %i ", dodatnie);
    printf( "\n suma elementow ujemnych: %i ", ujemne);

    return 0;
}