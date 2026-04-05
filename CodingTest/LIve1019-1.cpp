#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
    int id;
    float salary;
}Node;

Node* allocate_Memory(int* size)
{
    if (!scanf("%d", size))
    {
        puts("Input Error!");
        exit(EXIT_FAILURE);
    }
    
    Node* Table = (Node*)malloc((*size) * sizeof(Node));
    if (Table == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }
    
    return Table;
}

void read_Info_Employee(Node* Table, int i)
{
    if (!scanf("%d", &Table[i].id))
    {
        puts("Input Error!");
        exit(EXIT_FAILURE);
    }
    
    if (!scanf("%f", &Table[i].salary))
    {
        puts("Input Error!");
        exit(EXIT_FAILURE);
    }
}

void puts_Info_Employee(Node* Table, int i)
{
    printf("%d %.2f\n", Table[i].id, Table[i].salary);
}

int recursive_max_salary_id(Node *Table, int size)
{
    
       
    
}
int main()
{
    int size_main = 0;
    Node* Table_main = NULL;
    Table_main = allocate_Memory(&size_main);

    for (int i = 0; i < size_main; i++)
    {
        read_Info_Employee(Table_main, i);
    }
    
    free(Table_main);
    return 0;
}