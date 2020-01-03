#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int matrix_size = 0;
    printf("Wpisz ilosc elementow w macierze: ");
    scanf("%i", &matrix_size);
    while (matrix_size%2 != 0 || matrix_size < 4){
        printf("Wpisales zla liczbe, wpisz jeszcze raz: ");
        scanf("%i", &matrix_size);
    }
    int arr_size = matrix_size/2;
    int matrix[arr_size][arr_size];
    printf("Wpisz macierz kwadratowa w takim formacie: \n x1  x2 \n x3  x4 \n");

    for(int i = 0; i < arr_size; i++) {
        for(int j = 0; j < arr_size ; j++){
            int f;
            scanf("%d", &f);
            matrix[i][j] = f;
        }
    }
    int sum = 0;
    for(int i = 0; i < arr_size; i++){
        sum += matrix[i][i];
    }
    printf("suma = %i \n", sum);

    return 0;
}