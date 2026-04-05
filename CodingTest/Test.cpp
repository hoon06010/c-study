#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int key;
    struct Node* next;
}Node;

Node CreateNode(int Data)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    NewNode->key = Data;
    NewNode->next = NULL;

    return *NewNode;
}

int main()
{
    Node List = CreateNode(10);

    Node Node1 = CreateNode(20);
    List.next = &Node1;

    return 0;
}