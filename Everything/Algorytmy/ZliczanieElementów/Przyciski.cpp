#include <iostream>

void toy(const int tab[], int n, int m)
{
    int buttons[n + 1];
    for(int i = 0; i < n + 1; i++)
        buttons[i] = 0;
    int max = 0;
    int bufor = 0;

    for(int i = 0; i < m; i++)
    {
        if(tab[i] == n + 1)
        {
            bufor = max;
        }
        else
        {
            if(buttons[tab[i]] < bufor)
                buttons[tab[i]] = bufor + 1;
            else
                buttons[tab[i]]++;
            max = std::max(max, buttons[tab[i]]);
        }
    }

    std::cout << bufor << std::endl;
    for(int i = 0; i < n + 1; i++)
        if (buttons[i] < bufor)
            buttons[i] = bufor;

    for(int i = 1; i < n + 1; i++)
        std::cout << buttons[i] << " ";
    std::cout << std::endl;
}

auto main() -> int
{
    int tab[] = {3,4,4,6,1,4,4};
    toy(tab, 5, 7);
    return 0;
}
