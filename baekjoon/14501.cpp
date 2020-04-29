#include <stdio.h>
using namespace std;

int N;
int last_enable_day = 0;
int T[16];
int P[16];
bool visited[16] = {false, };
bool enable[16];
int result = 0;

void dfs(int idx, int sum)
{
        if(idx > last_enable_day) {
                result = result > sum ? result : sum;
                return;
        }
        
        if(!enable[idx]) 
        {
                dfs(idx + 1, sum);
                return;
        }
        
        visited[idx] = true;

        for(int i = idx + T[idx]; i <= N + 1; i++)
        {
                if(!visited[i]) {
                        dfs(i, sum + P[idx]);
                }
        }

        visited[idx] = false;
}

int main()
{
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
        {
                scanf("%d %d", &T[i], &P[i]);
        }

        for(int i = 1; i <= N; i++)
        {
                if(i + T[i] - 1 > N) enable[i] = false;
                else 
                {       
                        enable[i] = true;
                        last_enable_day = i;
                }
        }

        for(int i = 1; i <= N; i++)
        {
                dfs(i, 0);
        }

        printf("%d\n", result);
}
