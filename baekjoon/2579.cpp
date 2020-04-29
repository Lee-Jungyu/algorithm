#include <stdio.h>
using namespace std;

int N;
int stair[301];
int dp[301][2];

int getMax(int a, int b)
{
        return a > b ? a : b;
}

int main()
{
        scanf("%d\n", &N);
        for(int i = 1; i <= N; i++)
        {
                scanf("%d", &stair[i]);
        }
        dp[1][0] = stair[1];
        dp[1][1] = 0;
        if(N == 1)
        {
                printf("%d\n", getMax(dp[1][0], dp[1][1]));
                return 0;
        }
        dp[2][0] = stair[2];
        dp[2][1] = stair[1]+stair[2];
        if(N == 2)
        {
                printf("%d\n", getMax(dp[2][0], dp[2][1]));
                return 0;
        }

        else 
        {
                for(int i = 3; i <= N; i++)
                {
                        dp[i][0] = getMax(dp[i - 2][0], dp[i - 2][1]) + stair[i];
                        dp[i][1] = dp[i - 1][0] + stair[i];
                }

                printf("%d\n", getMax(dp[N][0], dp[N][1]));
                return 0;
        }
}
