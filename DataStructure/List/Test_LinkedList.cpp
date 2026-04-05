#include "LinkedList.h"

int main()
{
    int i = 0;
    int count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

    for (i = 0; i < 5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }
    
    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);
    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    count = SLL_GetNodeCount(List);
    for (int i = 0; i < count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("\nInsert 3000 After [2]...\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);

    SLL_InsertAfter(Current, NewNode);

    count = SLL_GetNodeCount(List);
    for (int i = 0; i < count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("\nDestroying List...\n");

    for (int i = 0; i < count; i++)
    {
        Current = SLL_GetNodeAt(List, 0);

        if (Current != NULL)
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }

    return 0;
}