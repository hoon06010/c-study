// Q1008
/*#include <stdio.h>

int main()
{
    printf("\u250C\u252C\u2510\n");
    printf("\u251C\u253C\u2524\n");
    printf("\u2514\u2534\u2518\n");

    return 0;
}*/

// Q1019
/*#include <stdio.h>

int main()
{
    int year, mon, day;
    scanf("%d.%d.%d", &year, &mon, &day);
    printf("%04d.%02d.%02d", year, mon, day);

    return 0;
}*/

// Q1024
#include <stdio.h>
#define MAX 20

int main()
{
    char word[MAX];
    scanf("%s", word);

    int i = 0;
    while (word[i] != '\0')
    {
        printf("'%c'\n", word[i]);
        i++;
    }
    
    return 0;
}