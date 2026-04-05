#include <stdio.h>
#include <stdlib.h>

typedef struct tagTable
{
    int score;
    int grade;
}Table;

Table* GetStudentScore(int* size);
void PostStudentScore(Table* table, int size);

int main()
{
    int size;
    Table* table = GetStudentScore(&size);
    
    PostStudentScore(table, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d %d\n", table[i].score, table[i].grade);
    }
    

    free(table);
    return 0;
}

Table* GetStudentScore(int* size)
{
    scanf("%d", size);

    Table* table = (Table*)malloc((*size)*sizeof(Table));
    if (table == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < *size; i++)
    {
        scanf("%d", &table[i].score);
        table[i].grade = 0;
    }
    
    return table;
}

void PostStudentScore(Table* table, int size)
{
    int count;
    for (int i = 0; i < size; i++)
    {
        count = 1;
        for (int j = 0; j < size; j++)
        {
            if (table[i].score < table[j].score)
            {
                count ++;
            }
        }
        table[i].grade = count;
    }
}