#include <iostream>
using namespace std;

int N, M;
int arr[9];

void solve(int cnt, int n)
{
	arr[n] = 1;
	if (cnt == M) {
		for (int i = 1; i <= N; i++)
		{
			if (arr[i] == 1)
				printf("%d ", i);
		}
		printf("\n");
		arr[n] = 0;
		return;
	}

	for (int i = n + 1; i <= N; i++) {
		if (arr[i] == 0) {
			solve(cnt + 1, i);
		}
	}

	arr[n] = 0;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		solve(1, i);
	}
}
