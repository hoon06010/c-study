#include "LinkedList.h"

Node* SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}

void SLL_DestroyNode(Node* Node)
{
    free(Node);
}

void SLL_DestroyAllNode(Node** Head)
{
    Node* Current = *Head;
    Node* Next;

    while (Current != NULL)
    {
        Next = Current->NextNode;
        
        free(Current);

        Current = Next;
    }

    *Head = NULL;
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        Node* Tail = *Head;
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
    }   
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewHead)
{
    if (*Head == NULL || *Head == Current)
    {
        NewHead->NextNode = *Head;
        *Head = NewHead;
    }
    else
    {
        Node* Temp = *Head;

        while (Temp != NULL && Temp->NextNode != Current)
        {
            Temp = Temp->NextNode;
        }
        
        if (Temp != NULL)
        {
            Temp->NextNode = NewHead;
            NewHead->NextNode = Current;
        }
    }
}

//???
void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if ((*Head) == NULL)
    {
        (*Head) = NewHead;
    }
    else
    {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

//???
void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if ((*Head) == Remove)
    {
        (*Head) = (*Head)->NextNode;
    }
    else
    {
        Node* Current = (*Head);
        
        while (Current != NULL && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }
        
        if (Current != NULL)
        {
            Current->NextNode = Remove->NextNode;
        }
    }
}

//???
Node* SLL_GetNodeAt(Node* Head, int location)
{
    Node* Current = Head;

    while (Current != NULL && location > 0)
    {
        Current = Current->NextNode;
        location--;
    }

    return Current;
}

int SLL_GetNodeCount(Node* Head)
{
    int count = 0;

    if (Head != NULL)
    {
        Node* Current = Head;

        while (Current != NULL)
        {
            Current = Current->NextNode;
            count++;
        }
    }
    
    return count;
}