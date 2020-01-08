#include <iostream>
using namespace std;

int N;
int A[1001];
int dp[1001] = { 0, };

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int biggest = 0;

	for (int i = 0; i < N; i++) {
		if (biggest < A[i]) biggest = A[i];

		int max = 0;
		for (int j = 1; j < A[i]; j++) {
			if (max < dp[j]) {
				max = dp[j];
			}
		}

		dp[A[i]] = max + 1;
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		if (result < dp[A[i]]) result = dp[A[i]];
	}

	printf("%d\n", result);
}
