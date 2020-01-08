#include <iostream>
using namespace std;

int N, M;
int arr[9];

void solve(int cnt, int n)
{
	arr[cnt] = n;
	if (cnt == M) {
		for (int i = 1; i <= cnt; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		solve(cnt + 1, i);
	}

}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		solve(1, i);
	}
}
