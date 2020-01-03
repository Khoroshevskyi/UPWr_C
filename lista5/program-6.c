#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int l, m ,n;
    printf("Podaj 3 liczby dla macierzy: ");
    scanf("%i %i %i", &l, &m, &n);

    int matrix_A[l][m];
    int matrix_B[m][n];
    int matrix_C[l][n];
    int r;

    // a
    printf("Macierz A: \n");
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < m; j++){
            r = rand() % 10;
            matrix_A[i][j] = r;
            printf("%i ", r);
        }
        printf("\n");
    }

    printf("\nMacierz B: \n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
            r = rand() % 10;
            matrix_B[i][j] = r;
            printf("%i ", r);
        }
        printf("\n");
    }

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < n; j++){
            matrix_C[i][j] = 0;
        }
    }

    // b
    for (int i =0; i < l; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }

    printf("\nMacierz C(A*B): ");
    for(int i = 0; i < l; i++) {
        printf("\n");
        for(int j = 0; j < n; j++){
            printf("%i ", matrix_C[i][j]);
        }
    }

    return 0;
}