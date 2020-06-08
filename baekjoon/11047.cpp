#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    vector<int> coins;

    scanf("%d", &N);
    scanf("%d", &K);

    coins.resize(N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &coins[i]);
    }

    int sum = 0;
    int flag = N - 1;
    while(K > 0) {
        int tmp = K - K % coins[flag];
        sum += tmp / coins[flag];
        K -= tmp;
        flag--;
    }

    printf("%d\n", sum);
}
//
