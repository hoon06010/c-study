#include <stdio.h>
#include <stdlib.h>

typedef struct tagTable
{
    int num;
    int re_sort;
}Table;

void alllocateMemory(Table** table, int* size);
void insertSorting(Table** table, int i);
int main()
{
    int size;
    Table* table;

    alllocateMemory(&table, &size);

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", table[i].num);
    }
    

    free(table);
    return 0;
}

void alllocateMemory(Table** table, int* size)
{
    scanf("%d", size);
    *table = (Table*)malloc(*size * sizeof(Table));
    if (*table == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *size; i++)
    {
        scanf("%d", &(*table)[i].num);
        (*table)[i].re_sort = (*table)[i].num;
        insertSorting(table, i);
    }
    
    
}

void insertSorting(Table** table, int i)
{
    int index, temp;
    temp = (*table)[i].re_sort;
    //인덱스 위치 찾기
    for (int index = 0; index < i; index++)
    {
        if (temp < (*table)[index].re_sort)
        {
            break;
        }
    }

    //뒤로 이동
    for (int j = i - 1; j >= index; j++)
    {
        (*table)[j].re_sort = (*table)[j - 1].re_sort;
    }

    //삽입??
    
}