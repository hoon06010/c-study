// #include <stdio.h>
// #include <stdlib.h>

// typedef int ElementType;

// typedef struct tagNode
// {
//     ElementType Data;
//     struct tagNode* NextNode;
// }Node;

// Node* SLL_CreateNode(ElementType NewData);
// void SLL_DestroyNode(Node* Node);
// void SLL_AppendNode(Node** Head, Node* NewNode);
// Node* SLL_GetNodeAt(Node* Head, int loctaion);
// Node* SLL_RemoveNode(Node** Head, Node* Remove);
// void SLL_InsertAfter(Node** Current, Node* NewNode);
// int SLL_GetNodeCount(Node** Head);

// int main()
// {
//     Node* List = NULL;
//     Node* MyNode = NULL;

//     SLL_AppendNode(&List, SLL_CreateNode(117));
//     SLL_AppendNode(&List, SLL_CreateNode(119));
//     SLL_AppendNode(&List, SLL_CreateNode(212));

//     MyNode = SLL_GetNodeAt(List, 1);
//     printf("Data = %d\n", MyNode->Data);

//     SLL_RemoveNode(&List, MyNode);

//     SLL_DestroyNode(MyNode);

//     Node* ToDestroy = NULL;
//     while (List != NULL)
//     {
//         ToDestroy = List;
//         List = List->NextNode;
//         SLL_DestroyNode(ToDestroy);
//     }
    

//     return 0;
// }

// Node* SLL_CreateNode(ElementType NewData)
// {
//     Node* NewNode = (Node*)malloc(sizeof(Node));

//     NewNode->Data = NewData;
//     NewNode->NextNode = NULL;

//     return NewNode;
// }
// void SLL_DestroyNode(Node* Node)
// {
//     free(Node);
// }
// void SLL_AppendNode(Node** Head, Node* NewNode)
// {
//     if ((*Head) == NULL)
//     {
//         *Head = NewNode;
//     }

//     else
//     {
//         Node* Tail = *Head;
//         while (Tail->NextNode != NULL)
//         {
//             Tail = Tail->NextNode;
//         }
        
//         Tail->NextNode = NewNode;
//     }
// }
// Node* SLL_GetNodeAt(Node* Head, int loctaion)
// {
//     Node* Current = Head;

//     while (Current != NULL && (--loctaion) >= 0)
//     {
//         Current = Current->NextNode;
//     }
    
//     return Current;
// }
// Node* SLL_RemoveNode(Node** Head, Node* Remove)
// {
//     if (*Head = Remove)
//     {
//         *Head = (*Head)->NextNode;
//     }
//     else
//     {
//         Node* Current = *Head;
//         while (Current != NULL && Current->NextNode != Remove)
//         {
//             Current = Current->NextNode;
//         }

//         if (Current != NULL)
//         {
//             Current->NextNode = Remove->NextNode;
//         }    
//     }
// }
// void SLL_InsertAfter(Node** Current, Node* NewNode)
// {
//     NewNode->NextNode = (*Current)->NextNode;
//     (*Current)->NextNode = NewNode;
// }
// int SLL_GetNodeCount(Node** Head)
// {
//     int Count = 0;
//     Node* Current = NULL;
    
//     while (Current != NULL)
//     {
//         Current = Current->NextNode;
//         Count++;
//     }

//     return Count;
// }