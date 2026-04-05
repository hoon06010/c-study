#include <stdio.h>
#include <stdlib.h>

typedef int Elementype;

typedef struct tagNode
{
    int Data;
    tagNode* PrevNode;
    tagNode* NextNode;
} Node;

Node* DLL_CreateNode(Elementype NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
Node* DLL_GetNodeAt(Node* Head, int Location);
void DLL_RemoveNodeAt(Node** Head, Node* Remove);
void DLL_InserAfter(Node* Current, Node* NewNode);
int DLL_GetNodeCount(Node* Head);

int main()
{
    printf("Hello World");

    return 0;
}

Node* DLL_CreateNode(Elementype NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

void DLL_DestroyNode(Node* Node)
{
    free(Node);
}

void DLL_AppendNode(Node** Head, Node* NewNode)
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
        NewNode->PrevNode = Tail;
    }
    
}

Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current->NextNode != NULL && (--Location)>0)
    {
        Current = Current->NextNode;
    }
    
    return Current;
}

void DLL_RemoveNodeAt(Node** Head, Node* Remove)
{
    if (Remove = NULL)
    {
        return;
    }
    
    if ((*Head) == Remove)
    {
        *Head = Remove->NextNode;
        if ((*Head) != NULL)
        {
            (*Head)->PrevNode = NULL;
        }
    }
    else
    {
        if (Remove->NextNode != NULL)
        {
            (Remove->PrevNode)->NextNode = Remove->NextNode;
        }

        if (Remove->PrevNode != NULL)
        {
            (Remove->NextNode)->PrevNode = Remove->PrevNode;
        }
    }

    Remove->NextNode = NULL;
    Remove->PrevNode = NULL;
}

void DLL_InserAfter(Node* Current, Node* NewNode)
{
    if (Current == NULL || NewNode == NULL)
    {
        return;
    }
    
    Node* OldNext = Current->NextNode;

    Current->NextNode = NewNode;
    NewNode->PrevNode = Current;

    if (OldNext != NULL)
    {
        OldNext->PrevNode = NewNode;
        NewNode->NextNode = OldNext;
    }
}

int DLL_GetNodeCount(Node* Head)
{
    int count = 0;
    Node* Temp = Head;

    while (Head != NULL || Head->NextNode != NULL)
    {
        Head = Head->NextNode;
        count++;
    }
    
    return count;
}