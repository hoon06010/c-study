#include <stdio.h>
#define MAX 20

typedef long long ll;

// I can solve this problem but it isn't efficient way. It's time complexity is O(N^2).
// I want to optimize this algorithm. Tell me only one step not for whole step.

int count_PartSum(ll S, ll arr[], int N){
    int count = 0;
    ll temp = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            temp += arr[j];
            if (temp == S)
            {
                count++;
            }
        }
        temp = 0;
    }

    return count;
}

int main(){
    ll S_main = 0, arr_main[MAX] = {0,};
    int N_main = 0;

    scanf("%d %lld", &N_main, &S_main);
    // read
    for (int i = 0; i < N_main; i++)
    {
        scanf("%lld", &arr_main[i]);
    }

    printf("%d", count_PartSum(S_main, arr_main, N_main));

    return 0;
}