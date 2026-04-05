// I fixed the simulate function only. Think about it only step by step.
#define time_quantum 3

#include <stdio.h>
#include <stdlib.h>

typedef struct tagProcess
{
    int id;
    int time_left;
}Process;

typedef struct tagNode
{
    Process process;
    tagNode* NextNode;
}Node;

Node* createNode(int id, int time_left)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }
    
    NewNode->process.id = id;
    NewNode->process.time_left = time_left;
    NewNode->NextNode = NULL;
    return NewNode;
}

void Q_insertNode(Node** Queue, Node* NewNode)
{
    if (*Queue == NULL)
    {
        *Queue = NewNode;
        return;
    }
    
    Node* Temp = *Queue;
    while (Temp->NextNode != NULL)
    {
        Temp = Temp->NextNode;
    }
    Temp->NextNode = NewNode;
}

void Q_destoryNode(Node** Queue)
{
    Node* Remove = *Queue;
    Node* Next = NULL;

    while (Remove)
    {
        Next = Remove->NextNode;
        free(Remove);
        Remove = Next;
    }
}

Process Q_deleteNode(Node** Queue)
{
    Process P = {(*Queue)->process.id, (*Queue)->process.time_left};

    Node* Temp = (*Queue)->NextNode;
    free(*Queue);
    *Queue = Temp;

    return P;
}

void simulate(Node** Queue)
{
    if (*Queue == NULL)
    {
        puts("The Queue is empty.");
        exit(EXIT_FAILURE);
    }

    Process process = {0,0};

    while (*Queue)
    {
        process = Q_deleteNode(&(*Queue));

        process.time_left -= time_quantum;
        
        // Focus on this part
        if (process.time_left > 0)
        {
            printf("Process [%d] paused\n", process.id);
            Q_insertNode(&(*Queue), createNode(process.id, process.time_left));
        }
        else
        {
            printf("Process [%d] completed\n", process.id);
        }
    }
}

int main()
{
    Node* Queue_main = NULL;

    Q_insertNode(&Queue_main, createNode(1, 10));
    Q_insertNode(&Queue_main, createNode(2, 4));
    Q_insertNode(&Queue_main, createNode(3, 7));

    simulate(&Queue_main);

    Q_destoryNode(&Queue_main);

    return 0;
}