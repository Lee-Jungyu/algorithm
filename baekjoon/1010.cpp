#include <iostream>
using namespace std;

int combination(int n, int m);

int dp[31][31] = { {1,}, };
int main()
{
	int T, n, m;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> m;
		cout << combination(n, m) << endl;
	}
	return 0;
}

int combination(int n, int m)
{
	int cnt;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 1) dp[i][j] = j;
			else if (i == j) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
			}
		}
	}
	return dp[n][m];
}

