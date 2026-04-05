#define MAX_N 40

#include <stdio.h>
#include <stdlib.h>

typedef struct tagCount
{
    int zero;
    int one;
}Count;

void fibonacci_count(int i, int num, Count counting[]) // int case는 왜 오류???
{
    if (num == 0)
    {
        counting[i].zero++;
    }
    else if (num == 1)
    {
        counting[i].one++;
    }
    else
    {
        fibonacci_count(i, num - 1, counting);
        fibonacci_count(i, num - 2, counting);
    }
}

// 경로찾기 문제라고 생각함
int main()
{
    int case_main = 0;
    Count counting_main[MAX_N] = {0,};

    fibonacci_count(case_main, 4, counting_main);

    printf("%d %d\n", counting_main[case_main].zero, counting_main[case_main].one);

    return 0;
}