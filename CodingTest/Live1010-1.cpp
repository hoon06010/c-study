#include <stdio.h>
#include <math.h>

int min(const int a, const int b)
{
    return a <= b ? a : b;
}

int main()
{
    int x_main = 0, y_main = 0,
    w_main = 0, h_main = 0;

    scanf("%d %d %d %d",
        &x_main, &y_main, &w_main, &h_main);

    printf("%d", min(min(x_main, abs(x_main - w_main)), min(y_main, abs(y_main - h_main))));
    
    return 0;
}