#include <iostream>
#define MOD 10007
using namespace std;

int dp[1001];
int sum[1001];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		sum[i] = (sum[i - 1] + dp[i - 1]) % MOD;

		if (i % 2) dp[i] = (sum[i] + 1) % MOD;
		else dp[i] = (dp[i - 1] % MOD * 2 + 1) % MOD;
	}

	cout << dp[n] << endl;

	return 0;
}
