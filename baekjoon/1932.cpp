#include <iostream>
using namespace std;

int N;
int triangle[501][501];
int dp[501][501];

int _max(int a, int b)
{
	if (a > b) return a;
	return b;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}

	dp[0][0] = triangle[0][0];

	int maxV = dp[0][0];

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][0] + triangle[i][0];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else {
				dp[i][j] = _max(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);
			}

			if (maxV < dp[i][j]) maxV = dp[i][j];
		}
	}

	printf("%d\n", maxV);
}
