#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
    int Data;
    tagNode* NextNode;
}Node;

Node* CreateNode(int Data)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }
    
    NewNode->Data = Data;
    NewNode->NextNode = NULL;

    return NewNode;
}

void PushNode(Node** Stack, Node* NewNode)
{
    if (*Stack == NULL)
    {
        *Stack = NewNode;
        return;
    }

    NewNode->NextNode = *Stack;
    Stack = &NewNode;
}

void DestroyAllNode(Node** Stack)
{
    if (*Stack == NULL)
    {
        return;
    }

    Node* Remove = *Stack;
    Node* Next = NULL;
    
    while (Remove != NULL)
    {
        Next = Remove->NextNode;
        free(Remove);
        Remove = Next;
    }
}

void Display(Node* Stack)
{
    Node* Temp = Stack;

    while (Temp != NULL)
    {
        printf("%d\n", Temp->Data);
        Temp = Temp->NextNode;
    }
}
int main()
{
    Node* Stack = NULL;

    PushNode(&Stack, CreateNode(10));
    PushNode(&Stack, CreateNode(20));
    PushNode(&Stack, CreateNode(30));
    PushNode(&Stack, CreateNode(40));

    Display(Stack);

    DestroyAllNode(&Stack);

    return 0;
}