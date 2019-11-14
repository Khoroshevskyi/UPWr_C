#include <stdio.h>


int ujemna(int liczba);
int dodatnia(int liczba);

// pierwsze zadanie - lista 3
int main(void)
{
    int naszaLiczba;
    printf("Enter an integer: ");
    scanf("%i", &naszaLiczba);
    printf("Our integer is: %i \n", naszaLiczba);

    int wynik;

    if (naszaLiczba >= 0)
    {
        wynik = dodatnia(naszaLiczba);
    } else {
        wynik = ujemna(naszaLiczba);
    }

    printf("Nasz wynik to: %i \n", wynik);
    return 0;
}

int ujemna(int liczba)
{
    int wynik = liczba*liczba;
    return wynik;
}

int dodatnia(int liczba)
{
    int wynik = 1;
    for (int i = 1; i <= liczba; i++)
    {
        wynik *= i;
    }
    return wynik;
}
