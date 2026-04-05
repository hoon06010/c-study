#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

int compare(const int* a, const int* b)
{
    return (*a > *b);
}

int calculateGCD(int num1, int num2)
{
    // Let num1 > num2
    int remain = num1 % num2;

    if (remain != 0)
    {
        return calculateGCD(num2, remain);
    }
    else
    {
        return num2;
    }
}

int main()
{
    int num1_main = 0,num2_main = 0, gcd_main = 0;
    int count = 0;
    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%d %d", &num1_main, &num2_main);

        if (compare(&num1_main, &num2_main))
        {
            gcd_main = calculateGCD(num1_main, num2_main);
        }
        else
        {
            gcd_main = calculateGCD(num2_main, num1_main);
        }

        ll lcm_main = 0;
        lcm_main = num1_main * num2_main / gcd_main;

        printf("%lld", lcm_main);
    }
    
    

    return 0;
}