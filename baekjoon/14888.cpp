#include <iostream>
using namespace std;

int N;
int arr[11];
int op[4];
int _min = 1111111111;
int _max = -1111111111;

void input()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &op[i]);
	}
}

void output() {
	printf("%d\n%d", _max, _min);
}

void dfs(int opCnt, int opNum, int num)
{
	opCnt++;

	int value;
	switch (opNum) {
	case 0:
		value = num + arr[opCnt];
		break;
	case 1:
		value = num - arr[opCnt];
		break;
	case 2:
		value = num * arr[opCnt];
		break;
	case 3:
		value = num / arr[opCnt];
		break;
	}

	if (opCnt == N - 1) {
		if (_min > value) _min = value;
		if (_max < value) _max = value;
	}

	for (int i = 0; i < 4; i++)
	{
		if (op[i]) {
			op[i]--;
			dfs(opCnt, i, value);
			op[i]++;
		}
	}
}


int main()
{
	input();
	for (int i = 0; i < 4; i++)
	{
		if (op[i]) {
			op[i]--;
			dfs(0, i, arr[0]);
			op[i]++;
		}
	}
	output();
}
