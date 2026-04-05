#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

/**
 * 정수를 1, 2, 3의 합으로 나타내는 모든 방법 -> 같은 것이 있는 순열!
 * 예를 들어 7
 * 1 -> 7 (1 + 1 + ...) (N)
 * 2 -> N / 2 (가능하면)
 * 3 -> N / 3 (가능하면)
 * 1, 2 -> 6 (N - 1)
 * 1, 3 -> 5 (N - 2) 여기까지는 해결!
 * 2, 3 -> (2, 2, 3) , (2, 3, 2), (3, 2, 2) ()
 * 1, 2, 3 -> (1, 1, 2, 3)
 */

/**
 * 1, 2
 * 1 1 1 1 1 1 1 1 1 1 1 1 (12)
 * 1 1 1 1 1 1 1 1 1 1 2
 * 1 1 1 1 1 1 1 1 2 2 
 * 1 1 1 1 1 1 2 2 2
 * 1 1 1 1 2 2 2 2 
 * 1 1 2 2 2 2 2
 * 2 2 2 2 2 2 
 * a + 2 * b = 12를 만족하는 모든 자연수의 쌍 a, b를 찾고 같은 것이 있는 순열로 계산... 너무 오래 걸리는데?
 * 1, 3 -> a + 3 * b = 12
 * 2, 3 -> 2 * a + 3 * b = 12
 * 1, 2 3 -> a + 2 * b + 3 * c = 12 -> 같은 것이 있는 순열
 */
ll factorial(int val)
{
    ll result = 1;
    for (int i = 1; i <= val; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int iter_main = 0, num_main = 0, arr_main[3] = {0,};
    scanf("%d", &num_main);
    printf("%lld\n", factorial(num_main));

    return 0;
}