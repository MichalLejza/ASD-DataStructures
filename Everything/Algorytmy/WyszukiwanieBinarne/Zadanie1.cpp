#include "iostream"

int *radius(const int *tab, size_t size)
{
    int *t = (int *)(malloc(sizeof(int) * size));
    int *sumy = (int *)(malloc(sizeof(int) * size));

    sumy[0] = tab[0];
    for (size_t i = 1; i < size; i++)
        sumy[i] = tab[i] + sumy[i - 1];

    for (size_t i = 0; i < size; i++)
    {
        int promien = -1;
        size_t start = 0;
        size_t end = size - 1;
        size_t middle = (start + end) / 2;

        while (start <= end)
        {
            int suma = 0;
            if (i - middle < 0)
            {
                
            }
            else if (i + middle >= size)
            {

            }
            else
            {

            }
        }
        t[i] = promien;
    }
    return t;
}

void printTab(int *tab, size_t size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << tab[i] << " ";
    std::cout << std::endl;
}

auto main() -> int
{
    size_t size = 6;
    int tab[] = {2,3,1,4,2,1};
    return 0;
}