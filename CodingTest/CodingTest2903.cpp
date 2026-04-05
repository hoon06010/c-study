#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

int main()
{
    int num = 0;
    int part_line = 0;
    scanf("%d", &num);

    if (num == 1)
    {
        printf("9");
    }
    else if (num == 2)
    {
        printf("25");
    }
    else
    {
        int part_line = num * (num - 1) / 2;
        int line = 2 * part_line + 3;
        printf("%d", line * line);
    }
    
    return 0;
}