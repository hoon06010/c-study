#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 256

typedef struct tagStudent
{
    int id;
    char name[MAX];
}Student;

void allocateMemory(Student** table, int* num);
void detectWaste(Student** table, int* current_student_count);
Student* insertSorting(Student** table, int* current_student_count, int temp_id, char temp_name[]);
Student* deleteElement(Student** table, int index, int* current_student_count);
void printId_Name(Student* table, int index);

int main()
{
    int num, currrent_student_count = 0, index;
    Student* table;

    allocateMemory(&table, &num);
    
    for (int i = 0; i < num; i++)
    {    
        detectWaste(&table, &currrent_student_count);
    }
    
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &index);
        printId_Name(table, index);
    }
    
    
    free(table);
    return 0;
}

void allocateMemory(Student** table, int* num)
{
    scanf("%d", num);

    *table = (Student*)calloc(*num, sizeof(Student));
    if (*table == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }
}

// 코딩테스트의 주제
void detectWaste(Student** table, int* current_student_count)
{
    //우선 입력값을 임시 변수에 저장하고 처리 코드(detect_code)와 수험 번호(id)에 따른 명령을 수행한다.
    char detect_code = '\0';
    int temp_id = 0;
    char temp_name[MAX] = {0,};
    scanf(" %c", &detect_code);
    scanf("%d", &temp_id);
    scanf("%s", temp_name);

    //find_duplicate 변수는 수험 번호의 일치 여부에 따른 작동 방식을 달리 하기 위한 변수이다. 값이 true이면 이미 table에 해당 id가 존재함을, 값이 false이면 그렇지 않음을 의미한다.
    bool find_duplicate = false;
    //로직의 순서는 처리 코드 'c'에 따라 크게 갈리기 때문에 if, else문을 이용하여 구분한다.
    if (detect_code == 'I')
    {
        //처리 코드의 값이 I일 경우이다. 이때 table에 입력된 수험번호가 있는지 for문을 통해 확인한다. 만약 입력된 수험 번화와 같은 수험 번호가 table에 존재한다면 find-duplicate의 값은 ture, 그렇지 않다면 flase로 유지된다.
        for (int j = 0; j < *current_student_count; j++)
        {
            if (temp_id == (*table)[j].id)
            {
                find_duplicate = true;
                break;
            }
        }

        //알고리즘은 입력된 수험 번호가 table에 존재하는 수험번호라면 아무 작업도 하지 않을 것을 요구한다. 그 반대의 경우에는 수험 번호와 이름을 table에 입력한다
            if (!find_duplicate)
            {
                *table = insertSorting(table, current_student_count, temp_id, temp_name);

            }
    }
    else
    {
        //처리 코드의 값이 'D'일 경우이다. 이때 table에 입력된 수험번호가 있는지 for문을 통해 확인한다. 만약 입력된 수험 번화와 같은 수험 번호가 table에 존재한다면 find-duplicate의 값은 ture, 그렇지 않다면 flase로 유지된다.
        int j;
        for (j = 0; j < *current_student_count; j++)
        {
            if (temp_id == (*table)[j].id)
            {
                find_duplicate = true;
                break;
            }
        }

        //알고리즘은 입력된 수험 번호가 table에 존재하는 수험번호라면 해당 수험 번호를 삭제할 것을 요구한다. 그에 따라 이 수험 번호에 대응하는 이름도 삭제되어야 한다. 그 반대의 경우에는 아무 작업도 하지 않을 것을 요구한다.
        if (find_duplicate)
        {
            *table = deleteElement(table, j, current_student_count);
        }
    }
}

Student* insertSorting(Student** table, int* current_student_count, int temp_id, char temp_name[])
{
    //인덱스 찾기
    int index;
    for (index = 0; index < *current_student_count; index++)
    {
        if(temp_id < (*table)[index].id)
        {
            break;
        }
    }
    
    //인덱스 뒤의 값 한 칸씩 밀기
    for (int i = *current_student_count - 1; i >= index; i--)
    {
        (*table)[i + 1].id = (*table)[i].id;
        strcpy((*table)[i + 1].name, (*table)[i].name);
    }
    
    //인덱스에 temp-id, temp_name 입력
    (*table)[index].id = temp_id;
    strcpy((*table)[index].name, temp_name);

    (*current_student_count)++;
    return *table;
}

Student* deleteElement(Student** table, int index, int* current_student_count)
{
    for (int i = index; i < *current_student_count - 1; i++)
    {
        (*table)[i].id = (*table)[i + 1].id;
        strcpy((*table)[i].name, (*table)[i + 1].name);
    }
    
    (*current_student_count)--;
    return *table;
}

void printId_Name(Student* table, int index)
{
    printf("%d ", table[index - 1].id);
    puts(table[index - 1].name);
}