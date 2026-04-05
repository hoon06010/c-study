/**
 * 코드 확인할 때 evalutate 함수를 집중해서 봐줘. 이 함수가 내가 푼 문제의 주제를 해결하는 함수고 나머지는 기본적인 함수야.
 * 문제를 읽고 나서 풀이 과정을 영어 문장으로 나눴어. 예를 들어 Read the string 단계의 함수를 다 작성하고 테스트한 다음에 다음 단계를 구현하기 시작했어.
 */

/**
 * Read the string (Clear)
 * Check if each single character is digit or alphabet. (Clear)
 * If it is a number, push it to the stack
 * If it is an operator, pop tow numbers in the stack, operate it, and push it to the stack.
 * Finally calcuate the result
 */

#define MAX_SIZE 256
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long ll;
typedef struct tagNode
{
    int Data;
    tagNode* NextNode;
}Node;

/**
 * 문제의 입력은 단 한계의 문자가 아닌 문자열을 한 번에 입력받아야 해서 문자열은 입력받는 함수인 N_des와 readExpression 함수를 구현했어.
 * 여기에서 문자열의 크기는 MAX_SIZE로 지정해서 풀었어.
 */
void N_des(char* str)
{
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
}
void readExpression(char* expression)
{
    puts("Type an string.");
    // why sizeof(expression) isn't working well?
    fgets(expression, MAX_SIZE, stdin);
    N_des(expression);
}

/**
 * 이 기능이 구현 된 다음에 Stack을 구현하기 시작했어.
 * 우선은 CreateNode(노드를 만드는 기능), S_pushNode(노드를 스택에 쌓는 기능), S_destroyNode(스택에 쌓은 노드를 해제하는 기능)만 구현하고 포인터에서 오류가 생기지 않는지 테스트했어.
 * 테스트를 한 다음에 S_display(스택에 저장된 데이터를 전부 보여주는 기능)을 구현해서 스택에 데이터가 잘 저장되었는지 확인했어. 이때 pushNode에 문제가 있다는 것을 알았고 이 함수를 고쳤어.
 * 이제 S_popNode(Top에 있는 Node의 데이터를 반환하고 그 노드를 삭제하는 기능)을 구현해서 데이터가 잘 출력되는지와 pop된 노드가 원래 스택에서 출력이 안 되는지 확인했어.
 */
Node* CreateNode(int Data)
{
    Node* NewNode = (Node*)calloc(1, sizeof(Node));
    if (NewNode == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }
    
    NewNode->Data = Data;
    NewNode->NextNode = NULL;

    return NewNode;
}

void S_pushNode(Node** Stack, Node* NewNode)
{
    if (*Stack == NULL)
    {
        *Stack = NewNode;
        return;
    }
    
    NewNode->NextNode = *Stack;
    *Stack = NewNode;
}

int S_popNode(Node** Stack)
{
    if (*Stack == NULL)
    {
        puts("Stack is empty");
        exit(EXIT_FAILURE);
    }
    
    int result = 0;

    Node* Temp = (*Stack)->NextNode;
    result = (*Stack)->Data;
    free(*Stack);
    *Stack = Temp;

    return result;
}

void S_destroyNode(Node** Stack)
{
    if ((*Stack) ==NULL)
    {
        puts("Stack is empty.");
        exit(EXIT_FAILURE);
    }
    
    Node* Remove = (*Stack);
    Node* Next = NULL;

    while (Remove)
    {
        Next = Remove->NextNode;
        free(Remove);
        Remove = Next;
    }
}

void S_display(Node* Stack)
{
    if (Stack == NULL)
    {
        puts("Stack is empty.");
        exit(EXIT_FAILURE);
    }
    
    Node* Temp = Stack;

    puts("===Display==");
    while (Temp)
    {
        printf("%d\n", Temp->Data);
        Temp = Temp -> NextNode;
    }
}

/**
 * 저 기능이 모두 충족되고 나서 함수를 구현하기 시작했어.
 * 우선 expression에 문자열이 잘 담겨서 오는지 확인하기 위해 for loop으로 모든 요소를 출력했어.
 * 그 다음 string에 있는 개별 문자를 숫자, 연산기호, 그 외의 것으로 구별하는 기능을 만들었어.
 * isdigit(문자가 숫자로 전환될 수 있는지 구별하는 함수)와 if 문을 사용해서 숫자를 구별하고 나머지는 switch를 사용해서 구별했어.
 * switch문으로 구별할 때는 개별 문자가 아닌 숫자로만 작동함을 알게 되어 연산자 기호에 대응하는 ASCII코드로 연산자를 구별했어.
 * 여기까지 구현한 다음에 각각의 문자를 잘 판단하는지 확인한 다음 다른 기능을 구현했어.
 */

/**
 * 이제는 숫자를 입력하면 push, 연산자를 입력하면 pop을 두 번 수행한 후 push하는 기능을 구현했어.
 * 숫자를 넣을 때 N(N >= 2)자리 수는 앞에 있는 수를 10을 곱하고 현재 있는 수를 더한 다음에 입력했어.
 * 연산자에 대응하는 연산 기호를 입력하는 그냥 읽어도 할 수 있을거야.
 */

/**
 * 아마도 ll기호를 처음 봤을 거야. 이거는 typedef long long ll;과 함께 설명해줄게.
 * long long은 정수값을 저장할 수 있는 변수형태야. 이게 int가 64,000정도??까지의 수밖에 저장할 수 없는데 문제의 요구사항은 이것보다 훨씬 큰 수를 저장해야 했어.
 * 그래서 long long을 사용했는데 문제에서 long long을 계속 쓰면 귀찮으니까 ll로 줄여 쓰겠다고 한거야.
 */
int evaluatePostfix(char* expression)
{
    ll result = 0;
    int ex_len = strlen(expression), val1 = 0, val2 = 0;
    char target = '\0';
    Node* Stack = NULL;
    
    for (int i = 0; i < ex_len; i++)
    {
        target = expression[i];
        
        if (isdigit(target))
        {
            int curr_value = target - '0';

            if (i > 0 && isdigit(expression[i - 1]))
            {
                int prev_value = S_popNode(&Stack);
                S_pushNode(&Stack, CreateNode(10 * prev_value + curr_value));
            }
            else
            {
                S_pushNode(&Stack, CreateNode(curr_value));
            }
            continue;
        }
        switch (target)
        {
        case 42: // *
            val1 = S_popNode(&Stack);
            val2 = S_popNode(&Stack);
            S_pushNode(&Stack, CreateNode(val1 * val2));
            break;
        case 43: // +
            val1 = S_popNode(&Stack);
            val2 = S_popNode(&Stack);
            S_pushNode(&Stack, CreateNode(val1 + val2));
            break;
        
        // Second Part - 1
        case 45: // -
            val1 = S_popNode(&Stack);
            val2 = S_popNode(&Stack);
            S_pushNode(&Stack, CreateNode(val2 - val1));
            break;
        // Second Part - 2
        case 47: // /
            val1 = S_popNode(&Stack);
            val2 = S_popNode(&Stack);
            S_pushNode(&Stack, CreateNode(val2 / val1));
            break;
        default:
            break;
        }
    }

    result = S_popNode(&Stack);
    return result;
}

int main()
{
    char expression_main[MAX_SIZE] = {0,};
    readExpression(expression_main);

    ll result_main = evaluatePostfix(expression_main);
    printf("Result = %lld\n", result_main);

    return 0;
}