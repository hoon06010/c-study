#include <stdio.h>
#include <stdlib.h>

int* allocateMemory(int* size)
{
    scanf("%d", size);

    int* ptr = (int*)malloc(*size * sizeof(int));
    if (ptr == NULL) exit(EXIT_FAILURE);
    
    for (int i = 0; i < *size; i++)
    {
        scanf("%d", &ptr[i]);
    }

    return ptr;
}

void subToZero(int element, int* B_find, int* C_find, long long* num_find)
{
    element -= *B_find;
    (*num_find)++;

    if (element < 1)
    {
        return;
    }
    
    if (element % (*C_find) == 0)
    {
        (*num_find) += element / (*C_find);
    }
    else
    {
        (*num_find) += element / (*C_find) + 1;
    }
}

long long count(int* ptr, int size, int B, int C)
{
    long long num = 0;
    
    for (int i = 0; i < size; i++)
    {
        subToZero(ptr[i], &B, &C, &num);
    }
    
    return num;
}

int main()
{
    int size_main = 0;
    int* ptr_main = NULL;

    ptr_main = allocateMemory(&size_main);
    
    int B_main = 0, C_main = 0;
    scanf("%d %d", &B_main, &C_main);

    printf("%lld", count(ptr_main, size_main, B_main, C_main));

    free(ptr_main);
    return 0;
}