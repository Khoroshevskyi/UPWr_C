#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int matrix_length = 4;
    int r;
    int matrix[matrix_length][matrix_length];
    for(int i = 0; i < matrix_length; i++) {
        for(int j = 0; j < matrix_length; j++){

            r = rand() % 10;
            matrix[i][j] = r;
        }
    }

    // a
    printf("(a) Nasza macierz: ");
    for(int i = 0; i < matrix_length;i++){
        printf("\n");
        for(int j = 0; j < matrix_length;j++){
            printf("%d ",matrix[i][j]);
        }
    }

    // b
    int sum = 0;
    for(int i = 0; i < matrix_length; i++){
        sum += matrix[i][i];
    }
    printf("\n(b) Suma elementow na glownej przekatnej wynosi = %i \n", sum);

    // c
    int sum1 = 0;
    for(int i = 0; i < matrix_length; i++)
    {
        for(int j = 0; j < i; j++)
        {
            sum1 += matrix[i][i];
        }
    }
    printf("\n(c) suma el. pod glowna przekatna = %i \n", sum1);

    // d
    int sum2 = 0;
    for(int i = 0; i < matrix_length; i++)
    {
        sum2 += matrix[1][i];
    }
    printf("\n(d) suma el. w drugim wierszu = %i \n", sum2);

    //e
    int sum3 = 0;
    for(int i = 0; i < matrix_length; i++)
    {
        sum3 += matrix[i][2];
    }
    printf("\n(e) suma el. w trzeciej kolumnie = %i \n", sum3);

    return 0;
}