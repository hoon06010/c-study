//method 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tagNode
{
    int Sum;
    int Strat_Index;
    int End_Index;
} Node;

int* GetArray(int* Num, bool* findPositive);
Node* P_FindTempSum(const int* Array, int num, int* count);
Node* F_FindTempSum(const int* Array, int num);
int FindMaxSumIndex(const Node* List, int count);
int Find_SequenceMaxSum(const Node* List, int center, const int* Array, int num);

int main(void)
{
    int num;
    bool findPositive = false;

    int* Array = GetArray(&num, &findPositive);

    Node* List = NULL;
    int count = 0;
    if (!findPositive)    
    {
        List = F_FindTempSum(Array, num);
        count++;
        printf("%d", List[0].Sum);

        free(List);
        free(Array);
        return 0;
    }

    List = P_FindTempSum(Array, num, &count);

    int Center = FindMaxSumIndex(List, count);

    int Seqeunce_Sum = Find_SequenceMaxSum(List, Center, Array, num);

    printf("%d", Seqeunce_Sum);

    free(Array);
    free(List);
    return 0;
}

int* GetArray(int* Num, bool* findPositive)
{
    scanf("%d", Num);
    int* Array = (int*)malloc(*Num * sizeof(int));
    if (Array == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *Num; i++)
    {
        scanf("%d", &Array[i]);

        if (Array[i] > 0)
        {
            *findPositive = true;
        }
    }
    
    return Array;
}

Node* P_FindTempSum(const int* Array, int num, int* count)
{
    Node* List = (Node*)calloc(num, sizeof(Node));
    if (List == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < num; i++)
    {
        if (Array[i] > 0)
        {
            if (List[*count].Sum == 0)
            {
                List[*count].Strat_Index = i;
            }
            List[*count].Sum += Array[i];
            
        }
        else 
        {
            if (List[*count].Sum > 0)
            {
                List[*count].End_Index = i - 1;
                (*count)++;
            }
        }
    }

    if (List[*count].Sum > 0)
    {
        List[*count].End_Index = num - 1;
        (*count)++;
    }
    
    return List;
}
Node* F_FindTempSum(const int* Array, int num)
{
    Node* List = (Node*)calloc(1, sizeof(Node));
    if (List == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }
    
    List[0].Sum = Array[0];
    for (int i = 1; i < num; i++)
    {
        if (Array[i] > List[0].Sum)
        {
            List[0].Sum = Array[i];
            List[0].Strat_Index = i;
            List[0].End_Index = i;
        }
    }

    return List;
}
int FindMaxSumIndex(const Node* List, int count)
{
    int temp_index = 0;
    for (int i = 0; i < count; i++)
    {
        if (List[i].Sum > List[temp_index].Sum)
        {
            temp_index = i;
        }
    }
    
    return temp_index;
}

int Find_SequenceMaxSum(const Node* List, int center, const int* Array, int num)
{
    int left_max_sum = 0, right_max_sum = 0;
    int current_max_sum = 0;

    for (int i = List[center].Strat_Index - 1; i >= 0; i--)
    {
        current_max_sum += Array[i];
        if (current_max_sum > left_max_sum)
        {
            left_max_sum = current_max_sum;
        }
    }
    
    current_max_sum = 0;
    for (int i = List[center].End_Index + 1; i < num; i++)
    {
        current_max_sum += Array[i];
        if (current_max_sum > right_max_sum)
        {
            right_max_sum = current_max_sum;
        }
    }
    
    return List[center].Sum + left_max_sum + right_max_sum;
}
//method 2
/*#include <stdio.h>
#include <stdlib.h>

int* AllocateMemory(int* count);
int Kadane_Algorithm(const int* List, int count);
int CompareNumber(const int a, const int b);

int main()
{
    int count = 0;
    int* List = AllocateMemory(&count);

    int SequenceMax = Kadane_Algorithm(List, count);

    printf("%d", SequenceMax);
    
    free(List);
    return 0;
}

int* AllocateMemory(int* count)
{
    scanf("%d", count);

    int* List = (int*)malloc(*count * sizeof(int));
    if (List == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *count; i++)
    {
        scanf("%d", &List[i]);
    }
    
    return List;
}
int CompareNumber(const int a, const int b)
{
    return (a > b) ? a : b;
}
int Kadane_Algorithm(const int* List, int count)
{
    int TempMax = List[0];
    int SequenceMax = List[0];

    for (int i = 1; i < count; i++)
    {
        TempMax = CompareNumber(List[i], TempMax + List[i]);
        
        SequenceMax = CompareNumber(TempMax, SequenceMax);
    }

    return SequenceMax;
}*/