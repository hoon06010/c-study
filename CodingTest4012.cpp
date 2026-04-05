#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tagStudent
{
    int score;
    int grade;
}Student;

Student* scanScores(int* num);
void rankGrade(Student** class_of_stu, int num);

int main()
{
    int num, i;
    Student* class_of_stu = scanScores(&num);
    
    rankGrade(&class_of_stu, num);

    for (int i = 0; i < num; i++)
        printf("%d %d\n", class_of_stu[i].score, class_of_stu[i].grade);

    free(class_of_stu);
    return 0;
}

Student* scanScores(int* num)
{
    puts("Enter the number of students.");
    if (scanf("%d", num) != 1 || *num < 1)
    {
        puts("Input Error!");
        exit(EXIT_FAILURE);
    }

    Student* class_of_stu = (Student*)malloc((*num) * sizeof(Student));
    if (class_of_stu == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }

    puts("Enter scores of students.");
    for (int i = 0; i < *num; i++)
    {
        if (scanf("%d", &class_of_stu[i].score) != 1 || class_of_stu[i].score < 0 || class_of_stu[i].score > 100)
        {
            puts("Input Error!");
            exit(EXIT_FAILURE);
        }
    }
    
    return class_of_stu;
}

void rankGrade(Student** class_of_stu, int num)
{
    int* temp = (int*)calloc(num, sizeof(int));
    int i, j;
    if (temp == NULL)
    {
        puts("Memory Allocation Error!");
        exit(EXIT_FAILURE);
    }
    
    int unique_count = 0;
    bool found_duplicate;
    for (i = 0; i < num; i++)
    {
        found_duplicate = true;
        for (j = 0; j < unique_count; j++)
            if ((*class_of_stu)[i].score == temp[j])
            {
                found_duplicate = false;
                break;
            }

        if (found_duplicate)
        {
            temp[unique_count++] = (*class_of_stu)[i].score;
        }
    }
    
    int temp_val;
    for (i = 0; i < (unique_count - 1); i++)
        for (j = 0; j < (unique_count - 1) - i; j++)
            if (temp[j] > temp[j + 1])
            {
                temp_val = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = temp_val;
            }
    
    int duplicate = 0, count = unique_count;
    for (i = 0; i < unique_count; i++)
    {
        count += duplicate;
        duplicate = 0;
        for (j = 0; j < num; j++)
        {
            if (temp[i] == (*class_of_stu)[j].score)
            {
                (*class_of_stu)[j].grade = count - i;
                duplicate++;
            }
        }
    }
}