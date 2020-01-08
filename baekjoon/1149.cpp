#include <iostream>
using namespace std;

int N;
int RGB[1001][3];
int dp[1001][3];

int _min(int a, int b) {
	if (a < b) return a;
	return b;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);
	}

	for (int i = 0; i < 3; i++) {
		dp[0][i] = RGB[0][i];
	}

	for (int i = 1; i < N; i++) {
		dp[i][0] = _min(dp[i - 1][1] + RGB[i][0], dp[i - 1][2] + RGB[i][0]);
		dp[i][1] = _min(dp[i - 1][0] + RGB[i][1], dp[i - 1][2] + RGB[i][1]);
		dp[i][2] = _min(dp[i - 1][0] + RGB[i][2], dp[i - 1][1] + RGB[i][2]);
	}

	int minV = _min(dp[N - 1][0], dp[N - 1][1]);
	minV = _min(minV, dp[N - 1][2]);

	printf("%d\n", minV);
}
