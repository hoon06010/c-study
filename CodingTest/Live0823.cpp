// SLL
/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct tagNode
{
    int Data;
    struct tagNode* NextNode;
}Node;

Node* SLL_CreateNode(int NewData);
void SLL_AppendNode(Node** Head, Node* NewNode);
void SLL_DestroyAllNode(Node* Head);
int SLL_FindNode(Node* Head, int target);

int main(void)
{
    Node* List = NULL;
    SLL_AppendNode(&List, SLL_CreateNode(10));
    SLL_AppendNode(&List, SLL_CreateNode(20));
    SLL_AppendNode(&List, SLL_CreateNode(30));
    SLL_AppendNode(&List, SLL_CreateNode(40));

    int target = 30;
    int idx = SLL_FindNode(List, target);

    if (idx == -1)
    {
        printf("숫자 %d는 리스트에 없습니다.\n", target);
    }
    else
    {
        printf("숫자 %d는 %d번째 위치에 있습니다.\n", target, idx);
    }
    

    SLL_DestroyAllNode(List);
    return 0;
}

Node* SLL_CreateNode(int NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode == NULL)
    {
        puts("Memory Allocation Errorz!");
        exit(EXIT_FAILURE);
    }
    
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}

void SLL_AppendNode(Node** Head, Node* NewNode)
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
    }
}

void SLL_DestroyAllNode(Node* Head)
{
    if (Head == NULL)
        return;
    else
    {
        Node* Remove = Head;
        Node* Next = NULL;

        while (Remove != NULL)
        {
            Next = Remove->NextNode;
            free(Remove);
            Remove = Next;
        }
    }
}
int SLL_FindNode(Node* Head, int target)
{
    int idx = 0;
    Node* Temp = Head;

    while (Temp != NULL)
    {
        if (Temp->Data == target)
        {
            break;
        }
        
        idx++;
        Temp = Temp->NextNode;
    }


    return idx;
}*/

//DLL
/*#include <stdio.h>
#include <stdlib.h>
typedef struct tagNode
{
    int Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
}Node;

Node* DLL_CreateNode(int NewData);
void DLL_AppendNode(Node** Head, Node* NewNode);
void DLL_DestoryAllNode(Node* Head);
void DLL_RemoveTail(Node** Head);
void DLL_PrintData(Node* Head);

int main(void)
{
    Node* List = NULL;
    DLL_AppendNode(&List, DLL_CreateNode(1));
    DLL_AppendNode(&List, DLL_CreateNode(2));
    DLL_AppendNode(&List, DLL_CreateNode(3));

    DLL_RemoveTail(&List);

    DLL_PrintData(List);

    DLL_DestoryAllNode(List);
    return 0;
}

Node* DLL_CreateNode(int NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;    
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
void DLL_DestoryAllNode(Node* Head)
{
    if (Head == NULL)
    {
        return;
    }
    else
    {
        Node* Remove = Head;
        Node* Next = NULL;

        while (Remove != NULL)
        {
            Next = Remove->NextNode;
            free(Remove);
            Remove = Next;
        }
    }
}
void DLL_RemoveTail(Node** Head)
{
    if ((*Head) == NULL)
    {
        return;
    }
    
    if ((*Head)->NextNode == NULL)
    {
        free(*Head);
        (*Head) = NULL;
        return;
    }
    
    Node* Tail = (*Head);

    while (Tail->NextNode != NULL)
    {
        Tail = Tail->NextNode;
    }
    
    Tail->PrevNode->NextNode = NULL;
    free(Tail);
}
void DLL_PrintData(Node* Head)
{
    if (Head == NULL)
    {
        return;
    }
    else
    {
        Node* Temp = Head;

        printf("마지막 노드 삭제 후 리스트: ");
        while (Temp != NULL)
        {
            printf("%d ", Temp->Data);
            Temp = Temp->NextNode;
        }
        puts("");
    }
}*/
