#include <iostream>
using namespace std;

int N, M;
int arr[9];

void solve(int cnt, int n)
{
	arr[n] = cnt;

	if (cnt == M) {
		for (int i = 1; i <= M; i++) {

			for (int j = 1; j < 9; j++) {
				if (arr[j] == i)
					printf("%d ", j);
			}
		}
		printf("\n");

		arr[n] = 0;
		return;
	}

	for (int i = 1; i <= N; i++) {
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
