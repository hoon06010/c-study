//Q1
/*#include <stdio.h>
#include <stdlib.h>

void read_str(char** s, int* size);
char *reverse_str(char* s, int size);

int main()
{
    char* s = NULL;
    char* r_s = NULL;
    int size;

    read_str(&s, &size);

    r_s = reverse_str(s, size);
    puts("Reversed String");
    puts(r_s);

    free(s);
    return 0;
}

void read_str(char** s, int* size)
{
    puts("Enter the size of string.");
    if (scanf("%d", size) != 1 || *size < 2)
    {
        puts("Please Enter an integer bigger than 2.");
        exit(EXIT_FAILURE);
    }

    *s = (char*)malloc(*size*sizeof(char));
    if(*s == NULL)
    {
        printf("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }
    
    puts("Enter the message.");
    getchar();
    for (int i = 0; i < *size; i++)
    {
        if (scanf("%c", &(*s)[i]) != 1)
        {
            puts("Enter the alphabet!");
            exit(EXIT_FAILURE);
        }
    }
    (*s)[*size] = '\0'; 
}

char *reverse_str(char* s, int size)
{
    char* r_s = (char*)malloc(size*sizeof(char));
    if (r_s == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++)
    {
        r_s[i] = s[(size - 1) - i];
    }
    r_s[size] = '\0';

    return r_s;
}*/

//Q2
/*#include <stdio.h>

void swap(int* a, int* b);

int main()
{
    int a = 0, b = 0;

    puts("Enter the two integers. (a, b)");
    scanf("%d, %d", &a, &b);
    printf("Before Swap: a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("After Swap: a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int* a, int* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}*/

//Q3
/*#include <stdio.h>
#define MAX_STUDENTS 10

void calculate(double score[], int stu, double *avg, int* max, int* min);

int main()
{
    double score[] = {0,};
    int stu, max, min;
    double avg;

    puts("Enter the number of students.");
    if (scanf("%d", &stu) != 1 || stu < 2 || stu > 10)
    {
        puts("Please enter the integer 2~10.");
        return 1;
    }

    for (int i = 0; i < stu; i++)
    {
        printf("Enter stu %d's score: ", i + 1);
        if (scanf("%lf", &score[i]) != 1 || score[i] < 0.0 || score[i] > 100)
        {
            puts("Enter the floating number 0 ~ 100.");
            return 1;
        }
    }
    
    calculate(score, stu, &avg, &max, &min);

    printf("Average: %.2lf\n", avg);
    printf("Max Score: %d\n", max);
    printf("Min Score: %d\n", min);

    return 0;
}

void calculate(double score[], int stu, double *avg, int* max, int* min)
{
    int i;

    for (i = 0; i < stu; i++)
        *avg += score[i];
    *avg /= stu;

    *max = score[0];
    *min = score[0];
    for (i = 0; i < stu; i++)
    {
        if (score[i] > *max)
            *max = score[i];
        if (score[i] < *min)
            *min = score[i];
    }
}*/

//Q4
/*#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct tagNode
{
    ElementType Data;
    struct tagNode* NextNode;
}Node;

Node* SLL_Create(ElementType NewData);
void SLL_DestoryNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);

int main()
{
    // 1. 리스트의 시작을 가리킬 포인터 (처음엔 비어있음)
    Node* List = NULL;

    // 2. 노드를 생성하여 리스트에 추가
    SLL_AppendNode(&List, SLL_Create(10));
    SLL_AppendNode(&List, SLL_Create(20));
    SLL_AppendNode(&List, SLL_Create(30));

    // 3. 리스트 순회 및 출력
    Node* Current = List;
    while (Current != NULL)
    {
        printf("데이터: %d\n", Current->Data);
        Current = Current->NextNode;
    }

    // 4. 리스트의 모든 노드 메모리 해제
    printf("\nDestroying List...\n");
    while (List != NULL)
    {
        Node* NodeToDestroy = List;
        List = List->NextNode; // 헤드를 다음 노드로 옮김
        SLL_DestoryNode(NodeToDestroy);
    }

    return 0;
}

Node* SLL_Create(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    // NewNode.Data = NewData;
    // NewNode.NextNode = NULL;

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}
void SLL_DestoryNode(Node* Node)
{
    free(Node);
}
void SLL_AppendNode(Node** Head, Node* NewNode)
{
    if ((*Head) == NULL)
        *Head = NewNode;

    else
    {
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL)
            Tail = Tail->NextNode;

        Tail->NextNode = NewNode;
    }
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagStudent
{
    char name[20];
    float score;
}Student;

int main()
{
    int n;
    puts("Enter the number of students.");
    if (scanf("%d", &n) != 1 || n < 2)
    {
        puts("Input Error!");
        exit(EXIT_FAILURE);
    }

    Student* Stu = (Student*)malloc(n*sizeof(Student));
    if (Stu == NULL)
    {
        puts("Input Error!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d. Enter the name of students: ", i + 1);
        scanf("%19s", Stu[i].name);
        printf("%d. Enter the score of students: ", i + 1);
        scanf("%f", &Stu[i].score);
    }
    
    for (int i = 0; i < n; i++)
    {
        puts(Stu[i].name);
        printf("%f\n", Stu[i].score);
    }

    free(Stu);

    return 0;
}

//승민
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct{
//     char name[50];
//     int score;
    
// }Student;

// int main(void){
    
//     /*
//     People p1;
//     People *q=&p1;
//     */
    
    
//     int num;
//     printf("Enter student number: ");
//     scanf("%d",&num);
    
//     Student *p=NULL;
//     p=(Student *)malloc(num*sizeof(Student));
//     if(p==NULL){
//         printf("Invalid..");
//         return 1;
//     }
    
    
    
//     for(int i=0;i<num;i++){
//         printf("Enter user name..\n");
//         scanf("%s",p[i].name);
        
//         printf("Enter user age..\n");
//         scanf("%d",&p[i].score);
        
//     }
//     for(int i=0;i<num;i++){
//         printf("Name: %s\nAge: %d",p[i].name,p[i].score);
//     }
    
//     free(p);
//     return 0;
    
// }