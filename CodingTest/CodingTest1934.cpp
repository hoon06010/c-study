#include <stdio.h>

int max(const int* a, const int* b)
{
    return (*a) > (*b) ? (*a) : (*b);
}
int min(const int* a, const int* b)
{
    return (*a) < (*b) ? (*a) : (*b);
}
int calculate_GCD(int num1, int num2)
{
    int max_local = 0, min_local = 0, remain = 0;
    
    max_local = max(&num1, &num2);
    min_local = min(&num1, &num2);
    remain = max_local % min_local;
    
    while (remain != 0)
    {
        
    }
    
    
}

int main()
{
    int num1_main = 0, num2_main = 0;
    scanf("%d %d", &num1_main, &num2_main);

    return 0;
}