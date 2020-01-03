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

    printf("\npowtarzajace sie elemnty: \n");
    for (int nr = 0; nr < n_elements; nr ++)
    {
        for (int nr1 = nr + 1; nr1 < n_elements; nr1 ++)
        {
            if (elementy[nr] == elementy[nr1]){

                int k = 1;
                for (int nr2 = 0; nr2 < nr; nr2 ++){
                    if (elementy[nr] == elementy[nr2])
                    {
                        k = 0;
                    }
                }
                if (k == 1){
                    printf( "%i ", elementy[nr]);
                    break;
                }
            }
        }
    }
    return(0);
}