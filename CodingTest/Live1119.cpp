#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
    int Data;
    tagNode* NextNode;
}Node;

typedef struct tagList
{
    Node* Head;
    Node* Tail;
    int Len;
}List;

Node* SLL_CreateNode(int Data)
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

void SLL_AppendNode(List** SLL, Node* NewNode)
{
    // Case 1: List is empty
    if ((*SLL)->Head == NULL)
    {
        (*SLL)->Head = NewNode;
        (*SLL)->Tail = NewNode; // IMPORTANT: Tail must point to the first node too!
    }
    // Case 2: List has items
    else
    {
        // Use the Tail pointer directly. No need to loop!
        (*SLL)->Tail->NextNode = NewNode;
        (*SLL)->Tail = NewNode; // Update Tail to be the new last node
    }
    (*SLL)->Len++;
}
void SLL_ScanLinkedList(List* SLL)
{
    Node* Temp = (*SLL).Head;
    while (Temp)
    {
        printf("%d\n", Temp->Data);
        Temp = Temp->NextNode;
    }
}

void SLL_DestroyLinkedList(List** SLL)
{
    Node* Temp = (*SLL)->Head;
    Node* Next = NULL;

    while (Temp)
    {
        Next = Temp->NextNode;
        free(Temp);
        Temp = Next;
    }

    free(*SLL); // WHY??
}

void SLL_Reorder(List** SLL, int Key)
{
    if ((*SLL)->Head == NULL) return;

    Node* Prev = NULL;
    Node* Curr = (*SLL)->Head;
    Node* Next = NULL;
    int Loop = (*SLL)->Len;

    for (int i = 0; i < Loop; i++)
    {
        Next = Curr->NextNode;
        
        if (Curr->Data >= Key)
        {
            if (Prev == NULL)
            {
                (*SLL)->Head = Next;
            }
            else
            {
                Prev->NextNode = Next;
            }

            Curr->NextNode = NULL;
            (*SLL)->Tail->NextNode = Curr;
            (*SLL)->Tail = Curr;
            Curr = Next;
        }
        else
        {
            Prev = Curr;
            Curr = Next;
        }   
    }
}

int main()
{
    List* SLL_main = (List*)calloc(1, sizeof(List));

    SLL_AppendNode(&SLL_main, SLL_CreateNode(7));
    SLL_AppendNode(&SLL_main, SLL_CreateNode(3));
    SLL_AppendNode(&SLL_main, SLL_CreateNode(9));
    SLL_AppendNode(&SLL_main, SLL_CreateNode(2));
    SLL_AppendNode(&SLL_main, SLL_CreateNode(5));
    SLL_AppendNode(&SLL_main, SLL_CreateNode(8));
    SLL_AppendNode(&SLL_main, SLL_CreateNode(1));
    
    SLL_Reorder(&SLL_main, 5);
    SLL_ScanLinkedList(SLL_main);
    
    SLL_DestroyLinkedList(&SLL_main);
    return 0;
}