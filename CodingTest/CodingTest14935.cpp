#include <stdio.h>
#include <stdlib.h>

void fa(int first, int count, int num, int arr[], int size)
{
    int temp = (num * count) % 10;

    if (first == temp)
    {
        puts("FA");
        exit(EXIT_SUCCESS);
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (temp == arr[i])
            {
                puts("NFA");
                exit(EXIT_FAILURE);
            }
        }
        arr[size++] = temp;
        fa(first, count, temp, arr, size);
    }
}

typedef long long ll;
int main()
{
    ll num_main = 0;
    scanf("%lld", &num_main);

    int first_main = 0, count_main = 1, arr_main[4] = {0,}, size_main = 0;
    first_main = num_main % 10;
    while (num_main > 10)
    {
        num_main = num_main / 10;
        count_main++;
    }

    fa(first_main, count_main, first_main, arr_main, size_main);

    return 0;
}