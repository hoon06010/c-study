#include <stdio.h>
#include <stdlib.h>

void zoom_in(int n)
{
    for (int i = 1; i < n + 1; i++) // i = 1, 2, 3, 4, 5
    {
        for (int j = 1; j < n * 4 + 1; j++) // j = 1, 2, 3, ... 13, 14,15
        {
            if (j <= n)
            {
                printf("%s ", "G");
            }
            else
            {
                printf("%s ", ".");
            }
        }
        puts("\n");
    }

    for (int i = 1; i < n + 1; i++) // i = 1, 2, 3, 4, 5
    {
        for (int j = 1; j < n * 4 + 1; j++) // j = 1, 2, 3, ... 13, 14,15
        {
            if (j <= n)
            {
                printf("%s ", ".");
            }
            else if (j <= 2 * n)
            {
                printf("%s ", "I");
            }
            else if (j <= 3 * n)
            {
                printf("%s ", ".");
            }
            else
            {
                printf("%s ", "T");
            }
        }
        puts("\n");
    }
    for (int i = 1; i < n + 1; i++) // i = 1, 2, 3, 4, 5
    {
        for (int j = 1; j < n * 4 + 1; j++) // j = 1, 2, 3, ... 13, 14,15
        {
            if (j <= 2 * n)
            {
                printf("%s ", ".");
            }
            else if (j <= 3 * n)
            {
                printf("%s ", "S");
            }
            else
            {
                printf("%s ", ".");
            }
        }
        puts("\n");
    }
}
int main()
{
    int n_main = 0;

    if (!scanf("%d", &n_main))
    {
        exit(EXIT_FAILURE);       
    }

    zoom_in(n_main);

    return 0;
}