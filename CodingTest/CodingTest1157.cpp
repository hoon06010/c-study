#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 256

typedef struct tagNode
{
    int count;
    struct tagNode* NextNode;
}Node;

int comp(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

void readString_changeUpper(char str[])
{
    fgets(str, MAX, stdin);
    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }

    qsort(str, strlen(str), sizeof(char), comp);
}

Node* SLL_createNode()
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }

    NewNode->count = 1;
    NewNode->NextNode = NULL;

    return NewNode;
}

void SLL_appendNode(Node** Head, Node* NewNode)
{
    if ((*Head) == NULL)
    {
        (*Head) = NewNode;
    }
    else
    {
        Node* Tail = (*Head);

        while (Tail -> NextNode != NULL)
        {
            Tail = Tail -> NextNode;
        }
        
        Tail -> NextNode = NewNode;
    }
}

void SLL_destroyAllNode(Node* Head)
{
    if (Head == NULL)
        return;
    else
    {
        Node* Remove = Head;
        Node* Next = NULL;

        while (Remove != NULL)
        {
            Next = Remove -> NextNode;
            
            free(Remove);

            Remove = Next;
        }
    }
}

void checkFrequency(Node** List, const char str[])
{
    int len = strlen(str);
    SLL_appendNode(&(*List), SLL_createNode());
    Node* Current = (*List);
    
    for (int i = 1; i < len; i++)
    {
        if (str[i] == str[i - 1])
        {
            Current->count++;
        }
        else
        {
            SLL_appendNode(&(*List), SLL_createNode());
            Current = Current->NextNode;
        }
    }
}

int findMaxIdx(Node* List, Node** List_Idx)
{
    int max = 0, idx = 0, count = 0, i = 0;
    Node* List_Current = List;

    Node* List_Current_Idx = (*List_Idx);

    while (List_Current)
    {
        if (List_Current->count > max)
        {
            max = List_Current->count;
        }
        List_Current = List_Current->NextNode;
    }
    
    List_Current = List;
    while (List_Current)
    {
        if (List_Current->count == max)
        {
            count++;
            idx = i;
        }
        
        if (count > 1)
        {
            return -1;
        }

        List_Current = List_Current->NextNode;
        i++;
    }

    return idx;
}

// Takes the sorted string and the target index of the unique character
void printMaxIdxChar(char sorted_str[], int target_idx)
{
    if (sorted_str[0] == '\0' || target_idx < 0) {
        return; // Handle empty string or invalid index
    }
    
    int unique_char_idx = 0;
    char target_char = sorted_str[0];

    // Loop through the string to find the correct unique character
    for (int i = 1; sorted_str[i] != '\0'; i++) {
        // If we find a new character, we've moved to the next unique block
        if (sorted_str[i] != sorted_str[i-1]) {
            unique_char_idx++;
        }
        
        // If our unique block index matches the target, we've found our character
        if (unique_char_idx == target_idx) {
            target_char = sorted_str[i];
            break; // Exit the loop once found
        }
    }
    
    printf("%c", target_char);
}
int main()
{
    char Upper_Sorted_List[MAX] = {0, };
    readString_changeUpper(Upper_Sorted_List);
    
    Node* Count_List = NULL;
    checkFrequency(&Count_List, Upper_Sorted_List);
    Node* Temp = Count_List;

    Node* Idx_List = NULL;
    int num = findMaxIdx(Count_List, &Idx_List);

    if (num == -1)
    {
        printf("%c", '?');
    }
    else
    {
        printMaxIdxChar(Upper_Sorted_List, num);
    }
    
    SLL_destroyAllNode(Idx_List);

    return 0;
}