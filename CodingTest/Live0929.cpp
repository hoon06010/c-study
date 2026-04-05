#include <stdio.h>

void printElement(int money)
{
    int unit[4] = {25, 10, 5, 1};
    int temp, remain[4] = {0, };

    scanf("%d", &money);
    for (int i = 0; i < 4; i++)
    {
        temp = money / unit[i];
        money -= temp * unit[i];
        printf("%d ", temp);
    }
    printf("\n");
}

int main()
{
    int count = 0;
    int money = 0;

    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &money);
        printElement(money);
    }
    
    return 0;
}
