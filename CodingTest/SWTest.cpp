#include <stdio.h>
#include <stdlib.h>

typedef struct tagPoint
{
    int x;
    int y;
}Point;

// 상(0), 하(1), 좌(2), 우(3) 순서의 좌표 변화량
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int can_connect(int r, int c, int dir, int N, int map[12][12]) {
    int curr_r = r + dr[dir];
    int curr_c = c + dc[dir];

    // 여기서부터 '벽'에 닿을 때까지 반복해서 이동하며 체크해야 합니다.
    while (curr_r >= 0 && curr_r < N && curr_c >= 0 && curr_c < N) {
        // 만약 0이 아닌 것(코어:1, 전선:2)을 만난다면?
        if (map[curr_r][curr_c] != 0)
        {
            return 0;
        }
        // 빈 공간(0)이라면 다음 칸으로 전진!
        curr_r += dr[dir];
        curr_c += dr[dir];
    }
    // 루프를 무사히 빠져나와 벽에 닿았다면 연결 가능!
    return 1;
}

int main()
{
    int N_main = 0;
    int arr_main[12][12] = {0,};

    Point IDX_ARR_main[12] = {0,};
    int count_main = 0;
    
    scanf("%d", &N_main);

    for (int i = 0; i < N_main; i++)
    {
        for (int j = 0; j < N_main; j++)
        {
            scanf("%d", &arr_main[i][j]);
            if (arr_main[i][j] == 1)
            {
                if (i == 0 || i == N_main - 1 || j == 0 || j == N_main - 1)
                {
                    continue;
                }
                IDX_ARR_main[count_main].x = i;
                IDX_ARR_main[count_main++].y = j;
            }
            
        }
    }

    puts("===");
    for (int i = 0; i < N_main; i++)
    {
        for (int j = 0; j < N_main; j++)
        {
            printf("%d ", arr_main[i][j]);
        }
        puts(" ");
    }

    for (int i = 0; i < count_main; i++)
    {
        printf("%d: (%d, %d)\n", i + 1, IDX_ARR_main[i].x, IDX_ARR_main[i].y);
    }
    
    
    return 0;
}