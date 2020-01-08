#include <iostream>
using namespace std;

int N;
int stair[301];
int dp[301][2];
int result;

int _max(int a, int b)
{
	if (a > b) return a;
	return b;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &stair[i]);

	dp[0][0] = stair[0];
	dp[0][1] = stair[0];

	if (N == 0) {
		result = dp[0][1];
		printf("%d\n", result);
	}

	dp[1][0] = stair[1];
	dp[1][1] = _max(dp[0][0] + stair[1], dp[1][0]);

	if (N == 1) {
		result = dp[1][1];
		printf("%d\n", result);
	}

	for (int i = 2; i < N; i++) {
		dp[i][0] = dp[i - 2][1] + stair[i];
		dp[i][1] = _max(dp[i - 1][0] + stair[i], dp[i][0]);
	}

	printf("%d\n", dp[N - 1][1]);
}
