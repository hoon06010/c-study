#include <stdio.h>

int Fibonacci(int n)
{
    int result = 0;

    if (!n)
    {
        result = 0;
    }
    else if (n == 1)
    {
        result = 1;
    }
    else
    {
        int temp1 = 0, temp2 = 1;
        for (int i = 1; i < n; i++)
        {
            result = temp1 + temp2;
            if (i % 2) temp1 = result;
            else temp2 = result;
        }
        
    }

    return result;    
}
int main()
{
    int n = 0;
    scanf("%d", &n);

    printf("%d", Fibonacci(n));

    return 0;
}