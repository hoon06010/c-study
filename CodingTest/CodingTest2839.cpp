#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int Arr_main[2] = {0,};
    int Num_main = 0;
    scanf("%d", &Num_main);

    Arr_main[0] = Num_main / 5;
    Num_main /= 5;
    
    if (Num_main % 3 != 0)
    {
        printf("-1");
        return 0;
    }
    Arr_main[1] = Num_main / 3;
    printf("%d", Arr_main[0] + Arr_main[1]);

    return 0;
}