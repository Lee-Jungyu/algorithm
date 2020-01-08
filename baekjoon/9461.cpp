#include <iostream>
using namespace std;

int T;
long long int dp[101];
int flag = 3;

int main()
{
	scanf("%d", &T);
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	while (T--) {
		int n;
		scanf("%d", &n);
		
		for (int i = flag; i < n + 1; i++) {
			dp[i] = dp[i - 3] + dp[i - 2];
		}

		printf("%llu\n", dp[n]);

	}
}
