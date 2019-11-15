#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *proste[] = {"jeden", "dwa", "trzy", "cztery", "piec", "szesc",
                    "siedem", "osiem", "dziewiec", "dziesiec", "jedenascie",
                    "dwanascie", "trzynascie", "czternascie", "petnascie",
                    "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie"};
    char *drugie[] = {"dziesiec", "dwadziescia", "trzydziesci", "czterdziesci",
                    "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat",
                    "dziewiecdziesiat"};
    char *trzecie[] = {"sto", "dwiescie", "trzysta", "czterysta", "piecset", "szejset",
                    "siedemset", "osiemset", "dziewiecset"};

    int our_integer;
    printf("Enter an integer: ");
    scanf("%i", &our_integer);

    printf("333 %s \n", proste[5]);


    if (our_integer <20 ) {
        printf("Slownie: %s \n", proste[(our_integer - 1)]);
    }
    else if (our_integer <100 ) {
        int result = (our_integer/10);
        int result1 = (our_integer%10);
        printf("Slownie: %s %s \n", drugie[result - 1], proste[(result1 - 1)] );
    }
    else if (our_integer < 999 ) {

        int result = (our_integer/100);

        if (20>(our_integer%100))
        {
            int result1 = our_integer%100;

            printf("result1: %i \n", result1);
            printf("Slownie: %s %s \n",trzecie[result - 1], proste[result1 - 1] );
        }
        else
        {
            int result1 = ((our_integer - result*100)/10);
            int result2 = (our_integer%10);
            printf("Slownie: %s %s %s \n",trzecie[result - 1], drugie[result1 - 1], proste[(result2 - 1)] );
        }

    }
    else {
        printf("Integer %i is too big! \n", our_integer);
        exit(0);
    }

}
