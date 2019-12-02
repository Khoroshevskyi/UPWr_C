#include <stdio.h>
#include <stdlib.h>

/* przepiszwejscie na wyjscie */
int main (void)
{
    int status = 0;
    char c;
    c = getchar();

    while (c != EOF)
    {
        if (status == 0){
            if (c == '/') { status = 1; }
            else { putchar(c); }
        }
        else if (status == 1){

            if (c == '/') { status = 2; }
            else if (c == '*') { status = 3; }
            else
            {
                status = 0;
                printf("/");
            }
        }
        else if (status == 2 && c == '\n')
        {
            status = 0;
        }
        else if (status == 3 && c == '*' )
        {
            status = 4;
        }
        else if (status == 4 && c == '/')
        {
            status = 0;
        }
        else if (status == 2 || status == 3 || status == 4) { }
        else { printf("Error occurred contact with developer . %i ", status); }
        c = getchar();

    }
    return EXIT_SUCCESS ;
}
