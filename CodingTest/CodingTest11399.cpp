#define SIZE_MAX 1000;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

void Selection_Sort(int Arr[], int Len)
{
    int max_idx = 0, max = 0, temp = 0;
    for (int i = 0; i < Len - 1; i++)
    {
        max = Arr[i];
        max_idx = i;
        for (int j = i + 1; j < Len; j++)
        {
            if (max < Arr[j])
            {
                max = Arr[j];
                max_idx = j;
            }
        }
        if (max_idx != i)
        {
            temp = Arr[i];
            Arr[i] = Arr[max_idx];
            Arr[max_idx] = temp;
        }
    }
}

ll CalculateSum(int Arr[], int Len)
{
    ll Sum = 0;
    
    for (int i = 0; i < Len; i++)
    {
        Sum += (i + 1) * Arr[i];
    }
    
    return Sum;
}

int main()
{
    int Len_main = 0;
    int Arr_main[1000] = {0,};
    
    scanf("%d", &Len_main);
    for (int i = 0; i < Len_main; i++)
    {
        scanf("%d", &Arr_main[i]);
    }    
    
    Selection_Sort(Arr_main, Len_main);

    printf("%lld", CalculateSum(Arr_main, Len_main));

    return 0;
}