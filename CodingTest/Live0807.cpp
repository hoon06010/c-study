//Method 1
/*#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
    int Data;
    struct tagNode* NextNode;
}Node;

Node* SLL_CreateNode(int NewData);
void SLL_ApppendNode(Node** Head, Node* NewNode);
void SLL_DestroyNodeAll(Node* Head);
void SLL_GetData(Node** Head, int num);
float CalculateMean(Node* Head, int num);

int main()
{
    int num;
    scanf("%d", &num);

    Node* List = NULL;

    SLL_GetData(&List, num);

    float mean = CalculateMean(List, num);
    printf("Mean = %.2f\n", mean);

    SLL_DestroyNodeAll(List);
    return 0;
}

Node* SLL_CreateNode(int NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}
//Should I use 'else'?
void SLL_ApppendNode(Node** Head, Node* NewNode)
{
    if (*Head == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        Node* Temp = *Head;

        while (Temp->NextNode != NULL)
        {
            Temp = Temp->NextNode;
        }
        
        Temp->NextNode = NewNode;
    }
}
void SLL_GetData(Node** Head, int num)
{
    int data;

    for (int i = 0; i < num; i++)
    {
        data = 0;
        scanf("%d", &data);
        SLL_ApppendNode(&(*Head), SLL_CreateNode(data));
    }
}
void SLL_DestroyNodeAll(Node* Head)
{
    Node* Temp = Head;
    Node* Next;

    while (Temp != NULL)
    {
        Next = Temp->NextNode;
        free(Temp);
        Temp = Next;
    }
}
//Then is it okay??
float CalculateMean(Node* Head, int num)
{
    if (num == 0)
    {
        puts("Value 'num' can't be 0");
        return 0;
    }
    
    float sum = 0;
    Node* Temp = Head;

    while (Temp != NULL)
    {
        sum += (float)Temp->Data;
        Temp = Temp->NextNode;
    }
    
    return sum/num;
}*/

//Method 2
#include <stdio.h>
#include <stdlib.h>
typedef struct tagNode
{
    int Data;
    struct tagNode* NextNode;
}Node;

Node* SLL_CreateNode(int NewData);
void SLL_AppendNode(Node** Head, Node* NewNode);
void SLL_DestroyNodeAll(Node* Head);

int main()
{
    Node* List = NULL;
    
    return 0;
}

Node* SLL_CreateNode(int NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode == NULL)
    {
        puts("MeMory Allocation Error!");
        exit(EXIT_FAILURE);
    }

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}
void SLL_AppendNode(Node** Head, Node* NewNode)
{
    if (*Head == NULL)
        *Head = NewNode;
    else
    {
        Node* Tail = *Head;

        while (Tail->NextNode != NULL)
            Tail = Tail->NextNode;
        
        Tail->NextNode = NewNode;
    }
}
void SLL_DestroyNodeAll(Node* Head)
{
    if (Head == NULL)
        return;
    else
    {
        Node* Remove = Head;
        if (Remove->NextNode == NULL)
        {
            free(Remove);
            return;
        }
        else
        {
            Node* Next = NULL;

            while (Remove != NULL)
            {
                Next = Remove->NextNode;
                free(Remove);
                Remove = Next;
            }
        }
    }
}