#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int Arr_main[10000] = {0,};
    int Num_main = 0, Len_main = 3, Size_main = -1;
    
    char Instr_main[10] = {0,};

    // scanf("%d", &Len_main);
    
    for (int i = 0; i < 5; i++)
    {
        scanf(" %s", Instr_main);
        printf("Instruction: %s\n", Instr_main);

        if (strcmp(Instr_main, "push") == 0)
        {
            scanf("%d", &Num_main);
            Arr_main[++Size_main] = Num_main;
        }
        else if (strcmp(Instr_main, "pop") == 0)
        {
            printf("Result = %d\n", Arr_main[Size_main]);
            Arr_main[Size_main--] = '\0';
        }
        else if (strcpy(Instr_main, "size") == 0)
        {
            printf("Result = %d\n", Size_main + 1);
        }
        else if (strcpy(Instr_main, "empty") == 0)
        {
            printf("Result = %d\n", (Size_main == -1));
        }
        else if (strcpy(Instr_main, "top") == 0)
        {
            if (Size_main == -1)
            {
                printf("Result = -1\n");
                continue;
            }
            printf("Result = %d\n", Arr_main[Size_main]);
        }

        for (int i = 0; i < 10; i++)
        {
            Instr_main[i] = '\0';
        }
    }
    return 0;
}