#include <iostream>
using namespace std;

int A[51][51];
int order[6][3];
bool visited[6] = { false, };
int N, M, K;
int result = 100000000;

void input()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		scanf("%d %d %d", &order[i][0], &order[i][1], &order[i][2]);
	}
}


void rotation(int r, int c, int s)
{
	int x = r - 1;
	int y = c - 1;
	int arr1[50];
	int arr2[50];
	int arr3[50];
	int arr4[50];

	for (int i = 1; i <= s; i++) {

		for (int j = 0; j < i * 2; j++) {
			arr1[j] = A[x - i][y - i + j];
			arr2[j] = A[x - i + j][y + i];
			arr3[j] = A[x + i][y + i - j];
			arr4[j] = A[x + i - j][y - i];
		}

		for (int j = 0; j < i * 2; j++) {
			A[x - i][y - i + 1 + j] = arr1[j];
			A[x - i + 1 + j][y + i] = arr2[j];
			A[x + i][y + i - 1 - j] = arr3[j];
			A[x + i - 1 - j][y - i] = arr4[j];
		}
	}
}

void reverse(int r, int c, int s) 
{
	int x = r - 1;
	int y = c - 1;
	int arr1[50];
	int arr2[50];
	int arr3[50];
	int arr4[50];

	for (int i = 1; i <= s; i++) {

		for (int j = 0; j < i * 2; j++) {
			arr1[j] = A[x - i][y - i + 1 + j];
			arr2[j] = A[x - i + 1 + j][y + i];
			arr3[j] = A[x + i][y + i - 1 - j];
			arr4[j] = A[x + i - 1 - j][y - i];
		}

		for (int j = 0; j < i * 2; j++) {
			A[x - i][y - i + j] = arr1[j];
			A[x - i + j][y + i] = arr2[j];
			A[x + i][y + i - j] = arr3[j];
			A[x + i - j][y - i] = arr4[j];
		}
	}
}

int getMin()
{
	int _min = 100000000;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = 0; j < M; j++)
		{
			sum += A[i][j];
		}

		if (_min > sum) {
			_min = sum;
		}
	}

	return _min;
}

void dfs(int cnt, int r, int c, int s) {
	
	rotation(r, c, s);

	if (cnt == K) {
		int _min = getMin();
		if (result > _min) result = _min;
		return;
	}

	for (int i = 0; i < K; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(cnt + 1, order[i][0], order[i][1], order[i][2]);
			reverse(order[i][0], order[i][1], order[i][2]);
			visited[i] = false;
		}
	}

}

void solve()
{
	for (int i = 0; i < K; i++) {
		visited[i] = true;
		dfs(1, order[i][0], order[i][1], order[i][2]);
		reverse(order[i][0], order[i][1], order[i][2]);
		visited[i] = false;
	}
}

void output()
{
	printf("%d\n", result);
}

int main()
{
	input();
	solve();
	output();
}

