#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
}Node;

Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNdoe(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
void DLL_InsertNode(Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);
int GetNodeCount(Node* Head);

#endif