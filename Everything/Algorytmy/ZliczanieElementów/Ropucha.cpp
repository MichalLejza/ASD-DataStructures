#include <iostream>

int leaf(const int tab[], int n, int m)
{
    int suma = 0;
    int count[m + 1];
    for(int i = 0; i < m + 1 ; i++)
        count[i] = 0;

    if(n < m)
        return -1;

    for(int i = 1; i <= m; i++)
        suma += i;

    for(int i = 0; i < n; i++)
    {
        if(suma == 0)
            return i;
        if(count[tab[i]] == 0)
        {
            count[tab[i]]++;
            suma -= tab[i];
        }
    }
    return -1;
}

auto main() -> int
{
    int tab[] = {1,3,1,4,2,3,5,4};
    std::cout << leaf(tab, 8, 5);
    return 0;
}
