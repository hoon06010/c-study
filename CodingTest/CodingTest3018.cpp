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
        detectWaste(&table, &currrent_student_count);
    
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

void detectWaste(Student** table, int* current_student_count)
{
    char detect_code = '\0';
    int temp_id = 0, i;
    char temp_name[MAX] = {0,};
    scanf(" %c", &detect_code);
    scanf("%d", &temp_id);
    scanf("%s", temp_name);

    bool find_duplicate = false;
    for (i = 0; i < *current_student_count; i++)
        if (temp_id == (*table)[i].id)
        {
            find_duplicate = true;
            break;
        }
    
    if (detect_code == 'I')
        if (find_duplicate)
            *table = insertSorting(table, current_student_count, temp_id, temp_name);
    else
        if (find_duplicate)
            *table = deleteElement(table, i, current_student_count);
}

Student* insertSorting(Student** table, int* current_student_count, int temp_id, char temp_name[])
{
    //인덱스 찾기
    int index, i;
    for (index = 0; index < *current_student_count; index++)
        if(temp_id < (*table)[index].id)
            break;
    
    //인덱스 뒤의 값 한 칸씩 밀기
    for (i = *current_student_count - 1; i >= index; i--)
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
/*    if (detect_code == 'I')
    {
        for (int j = 0; j < *current_student_count; j++)
        {
            if (temp_id == (*table)[j].id)
            {
                find_duplicate = true;
                break;
            }
        }
            if (!find_duplicate)
            {
                *table = insertSorting(table, current_student_count, temp_id, temp_name);
            }
    }
    else
    {
        int j;
        for (j = 0; j < *current_student_count; j++)
        {
            if (temp_id == (*table)[j].id)
            {
                find_duplicate = true;
                break;
            }
        }
        if (find_duplicate)
        {
            *table = deleteElement(table, j, current_student_count);
        }
    }*/