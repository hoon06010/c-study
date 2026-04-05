#include "DoublyLinkedList.h"

Node* DLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

void DLL_DestroyNdoe(Node* Node)
{
    free(Node);
}

void DLL_AppendNode(Node** Head, Node* NewNode)
{
    if ((*Head) == NULL)
    {
        (*Head) = NewNode;
    }
    else
    {
        Node* Tail = (*Head);

        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }
        
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}

void DLL_InsertNode(Node* Current, Node* NewNode)
{
    if (Current->NextNode != NULL)
    {
        (Current->NextNode)->PrevNode = NewNode;
        NewNode->NextNode = Current->NextNode;
    }

    NewNode = Current->NextNode;
    Current = NewNode->PrevNode;
}

void DLL_RemoveNode(Node** Head, Node* Remove)
{
    if ((*Head) == Remove)
    {
        Remove->NextNode->PrevNode = NULL;
        Remove->NextNode = NULL;

        (*Head) = (*Head)->NextNode;
    }
    else
    {
        Remove->PrevNode->NextNode = NULL;
        Remove->PrevNode = NULL;

        if (Remove->NextNode != NULL)
        {
            Remove->NextNode->PrevNode = NULL;
            Remove->NextNode = NULL;
        }
    }
}
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Temp = Head;

    while (Temp != NULL && (--Location)>0)
    {
        Temp = Temp->NextNode;
    }
    
    if (Temp != NULL)
        return Temp;
    else
        return NULL;
}
int GetNodeCount(Node* Head)
{
    int Count = 0;
    Node* Temp = Head;

    while (Temp != NULL)
    {
        Temp = Temp->NextNode;
        Count++;
    }
    
    return Count;
}