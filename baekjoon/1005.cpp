#include <iostream>
#include <string.h>
using namespace std;

int T; //tc
int N; //건물의 개수
int K; //건물간의 건설규칙의 총 개수
int X, Y, W; //건설 순서, 건물 번호
int D; // 건설에 걸리는 시간

int build[1001]; //각 건물마다 걸리는 시간
int edge[1001][1001];
int first[1001];
int dp[1001];
void init()
{
	memset(build, 0, sizeof(build));
	memset(edge, 0, sizeof(edge));
	memset(first, -1, sizeof(first));
	memset(dp, -1, sizeof(dp));
}

int findV(int curr)
{
	if (dp[curr] != -1) {
		return dp[curr];
	}
	if (first[curr]) {
		dp[curr] = build[curr];
		return dp[curr]; 
	}

	int max = 0;
	
	for (int i = 1; i <= N; i++)
	{
		if (edge[i][curr])
		{
			int f = findV(i);
			if (max < f) {
				max = f;
			}
		}
	}

	dp[curr] = max + build[curr];
	return dp[curr];
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		init();

		scanf("%d %d", &N, &K);
		for (int n = 1; n <= N; n++)
		{
			scanf("%d \n", &D);
			build[n] = D;
		}
		for (int k = 1; k <= K; k++)
		{
			scanf("%d %d\n", &X, &Y);
			edge[X][Y] = 1;
			first[Y] = 0;
		}
		scanf("%d", &W);

		int result = findV(W);

		printf("%d\n", result);
	}
}

