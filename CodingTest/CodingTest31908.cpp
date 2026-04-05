#define STR_MAX 50
#define PEO_MAX 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagPeople
{
    char Name[STR_MAX];
    char Ring[STR_MAX];
}People;

int main()
{
    People people_main[PEO_MAX] = {0,};

    int num_main = 0;
    if (!scanf("%d", &num_main))
    {
        puts("num_main scan error");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < num_main; i++)
    {
        if (!scanf(" %s %s", people_main[i].Name, people_main[i].Ring))
        {
            printf("people[%d] scan error\n", i);
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}