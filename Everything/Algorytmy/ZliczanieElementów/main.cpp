#include <iostream>
#include <cstdlib>
#include <vector>

void countCounter(const int A[], const int B[], int n, int m)
{
    int sumaA = 0, sumaB = 0, d;
    int zlicz[m + 1];
    for(int i = 0; i < n; i++)
    {
        sumaA += A[i];
        sumaB += B[i];
    }

    bool wynik = false;
    d = sumaB - sumaA;

    if (d % 2 == 0)
    {
        d /= 2;
        for(int i = 0; i < n; i++)
            zlicz[A[i]]++;
        for(int i = 0; i < n; i++)
            if (0 <= B[i] - d && B[i] - d <= m && zlicz[B[i] - d] > 0)
                wynik = true;
    }
}

void worseCountCounter(const int A[], const int B[], int n, int m)
{
    int sumaA = 0, sumaB = 0, d;
    int zlicz[m + 1];
    for(int i = 0; i < n; i++)
    {
        sumaA += A[i];
        sumaB += B[i];
    }

    bool wynik = false;
    int zmiana = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            zmiana = B[j] - A[i];
            sumaA += zmiana;
            sumaB -= zmiana;
            if(sumaA == sumaB)
                wynik = true;
            sumaA -= zmiana;
            sumaB += zmiana;
        }
    }
}

auto main() -> int
{
    auto tab = {2,3,5,1,2,4,9,10,2,4,1,2};

    return 0;
}
