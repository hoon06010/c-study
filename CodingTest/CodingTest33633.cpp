//Method 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct tagNode
{
    int val;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
}Node;

// DLL Basic function
Node* DLL_CreateNode(int len);
void DLL_AppendNode(Node** Head, Node* NewNode);
void DLL_DestroyAllNode(Node* Head);
/// @brief Allocate unique hailstone sequence to Temp->Array. 
/// @param Temp Save hailstone sequence in it's Array
/// @param len Hailstone's length
/// @return Check if it have temp[1];
bool HailstoneSequence(Node** Temp, int len);
int AllocateHsNode(Node** List, int len);

int main(void)
{
    int len = 0;
    Node* List = NULL;
    scanf("%d", &len);
    
    int count = AllocateHsNode(&List, len);
    printf("%d\n", count);

    Node* Current = List;
    for (int i = 0; i < count; i++)
    {
        printf("%d\n", Current->val);
        Current = Current->NextNode;
    }
    
    DLL_DestroyAllNode(List);
    return 0;
}

Node* DLL_CreateNode(int len)
{
    Node* Temp = (Node*)malloc(sizeof(Node));
    if (Temp == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }

    //Initialization
    Temp->val = 0;
    Temp->PrevNode = NULL;
    Temp->NextNode = NULL;

    return Temp;
}
void DLL_AppendNode(Node** Head, Node* NewNode)
{
    if (*Head == NULL)
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
void DLL_DestroyAllNode(Node* Head)
{
    if (Head == NULL)
    {
        return ;
    }
    else
    {
        Node* Remove = Head;

        if (Remove->NextNode == NULL)
        {
            free(Remove);
        }
        else
        {
            Node* Next = NULL;

            while (Remove != NULL)
            {
                Next = Remove->NextNode;
                free(Remove);

                Remove= Next;
            }
        }
    }
}
bool HailstoneSequence(Node** Temp, int len)
{
    bool code = true;
    
    //First, make int pointer to allocate to node
    int* ptr = (int*)malloc(len * sizeof(int));
    if (ptr == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }

    //Second, consider two possibility of hailstone sequence's element
    int temp[2];
    ptr[0] = 1;
    for (int i = 1; i < len; i++)
    {
        temp[1] = 0;

        // Two Possibility
        temp[0] = ptr[i - 1] * 2;
        if (ptr[i - 1] % 3 == 1)
        {
            temp[1] = (ptr[i - 1] - 1) / 3;
        }

        // ptr[i] is equal to temp[1] only if temp[1] exists and it doesn't equal to element of PrevNode's Array
        if (temp[1] != 0)
        {
            if ((*Temp) -> PrevNode != NULL)
            {
                if (temp[1] != (*Temp)->PrevNode->val)
                {
                    ptr[i] = temp[1];
                    code = false;
                }
                else
                {
                    ptr[i] = temp[0];
                }
            }
            else
            {
                ptr[i] = temp[0];
            }
        }
        // Else, value of temp[0] is allocated to ptr[i]
        else
        {
            ptr[i] = temp[0];
        }
    }
    
    (*Temp)->val = ptr[len - 1];
    return code;
}
int AllocateHsNode(Node** List, int len)
{
    int count = 0;
    bool code;

    do
    {
        Node* Temp = DLL_CreateNode(len);
        code = HailstoneSequence(&Temp, len);
        DLL_AppendNode(&(*List), Temp);
        count++;
    } while (len < 4 || code == true);

    return count;
}

//Method 2
#include <stdio.h>
#include <stdlib.h>

// long long: 우박수열의 값은 매우 커질 수 있으므로 int 대신 사용
typedef long long ll;

// qsort를 위한 비교 함수 (오름차순)
int compare(const void* a, const void* b) {
    ll num1 = *(ll*)a;
    ll num2 = *(ll*)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

// 결과를 저장할 동적 배열에 값을 추가하는 함수
void add_result(ll** results, int* count, int* capacity, ll value) {
    if (*count == *capacity) {
        *capacity *= 2;
        *results = (ll*)realloc(*results, (*capacity) * sizeof(ll));
        if (*results == NULL) {
            puts("Memory Re-allocation Error!");
            exit(EXIT_FAILURE);
        }
    }
    (*results)[(*count)++] = value;
}

/**
 * @brief 재귀적으로 역방향 우박수열을 탐색하는 함수
 * @param current_num 현재 항의 값
 * @param current_len 현재까지의 수열 길이
 * @param target_len 목표 수열 길이
 * @param results A_1 결과값을 저장할 동적 배열
 * @param count 결과값의 개수
 * @param capacity 결과 배열의 현재 용량
 */
void find_sequences(ll current_num, int current_len, int target_len, 
                      ll** results, int* count, int* capacity) {
    // 목표 길이에 도달하면, 현재 숫자가 A_1이므로 결과에 추가하고 종료
    if (current_len == target_len) {
        add_result(results, count, capacity, current_num);
        return;
    }

    // 다음 항(역방향)을 탐색
    // 규칙 1: A_i = A_{i+1} * 2
    ll next_num1 = current_num * 2;
    find_sequences(next_num1, current_len + 1, target_len, results, count, capacity);

    // 규칙 2: A_i = (A_{i+1} - 1) / 3
    // 조건: (현재값 - 1)이 3으로 나누어 떨어져야 하고, 그 결과가 1이 아니어야 함 (문제 조건)
    if ((current_num - 1) % 3 == 0) {
        ll next_num2 = (current_num - 1) / 3;
        if (next_num2 > 1 && next_num2 % 2 != 0) { // 결과가 1보다 큰 홀수일 때만 유효
            find_sequences(next_num2, current_len + 1, target_len, results, count, capacity);
        }
    }
}

int main(void) {
    int N;
    scanf("%d", &N);

    if (N <= 0) {
        printf("0\n");
        return 0;
    }

    // 결과를 저장할 동적 배열 초기화
    int result_count = 0;
    int capacity = 10; // 초기 용량
    ll* results = (ll*)malloc(capacity * sizeof(ll));
    if (results == NULL) {
        puts("Memory Allocation Error!");
        return 1;
    }

    // A_N = 1, 현재 길이 1에서 탐색 시작
    find_sequences(1, 1, N, &results, &result_count, &capacity);

    // 찾은 결과들을 오름차순으로 정렬
    qsort(results, result_count, sizeof(ll), compare);

    // 결과 출력
    printf("%d\n", result_count);
    for (int i = 0; i < result_count; i++) {
        printf("%lld\n", results[i]);
    }

    free(results);
    return 0;
}