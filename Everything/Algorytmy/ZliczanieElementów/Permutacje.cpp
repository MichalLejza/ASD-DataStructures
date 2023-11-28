#include <iostream>

bool check(int tab[], int n)
{
    int maxElement = 0;
    int suma = 0;

    for(int i = 0; i < n; i++)
    {
        tab[i] >= maxElement ? maxElement = tab[i] : maxElement = maxElement;
        suma += tab[i];
    }

    for(int i = 1; i <= maxElement; i++)
        suma -= i;

    return suma == 0;
}

auto main() -> int
{
    int tab[] = {7,1,4,3};
    check(tab, 4) ? std::cout << "Tak\n" : std::cout << "Nie\n";
    return 0;
}
