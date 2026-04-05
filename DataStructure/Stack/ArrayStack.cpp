#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
}Node;

typedef struct tagArrayStack
{
    int Capacity;
    int Top;
    Node* Node;
} ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
    if (Stack == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }
    
    (*Stack)->Node = (Node*)malloc(Capacity*sizeof(Node));
    if ((*Stack)->Node == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }

    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack)
{
    free(Stack->Node);
    free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data)
{
    Stack->Node[++(Stack->Top)].Data = Data;
}

ElementType AS_Pop(ArrayStack* Stack)
{
    int Position = Stack->Top--;
    return Stack->Node[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack)
{
    return Stack->Node[Stack->Top].Data;
}

int AS_GetSize(ArrayStack* Stack)
{
    return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack* Stack)
{
    return (Stack->Top == -1);
}

int AS_IsFull(ArrayStack* Stack)
{
    return (Stack->Top + 1 == Stack->Capacity);
}