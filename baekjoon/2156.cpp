#include <iostream>
using namespace std;

int N;
int arr[10001];
int dp[10001];

int getMax(int a, int b, int c) {
	if (a > b) {
		if (a > c) return a;
		else return c;
	}
	else {
		if (b > c) return b;
		else return c;
	}
}
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	dp[0] = arr[0];
	if (N == 1) {
		printf("%d\n", dp[0]);
		return 0;
	}

	dp[1] = arr[0] + arr[1];
	if (N == 2) {
		printf("%d\n", dp[1]);
		return 0;
	}

	dp[2] = getMax(dp[0] + arr[2], dp[1], arr[1] + arr[2]);
	if (N == 3) {
		printf("%d\n", dp[2]);
		return 0;
	}

	for (int i = 3; i < N; i++) {
		dp[i] = getMax(dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	printf("%d\n", dp[N - 1]);
}
