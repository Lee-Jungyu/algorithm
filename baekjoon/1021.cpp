#include <iostream>
using namespace std;

int q[51];
int pickPoint;
int currPoint;
int result;
int N, M;

int moveLeft(int n)
{
	int cnt = 0;
	currPoint = pickPoint + N;
	while (currPoint % N != n)
	{
		currPoint--;
		if (q[currPoint % N] == 1) continue;
		cnt++;
	}

	return cnt;
}

int moveRight(int n)
{
	int cnt = 0;
	currPoint = pickPoint;
	while (currPoint % N != n)
	{
		currPoint++;
		if (q[currPoint % N] == 1) continue;
		cnt++;
	}
	return cnt;
}

void findPoint()
{
	while (q[pickPoint % N] == 1) {
		pickPoint++;
	}
}


int main()
{
	result = 0;
	currPoint = 0;
	pickPoint = 0;
	int picked = 0;
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < M; i++)
	{
		int n;
		scanf("%d", &n);

		int l = moveLeft(n - 1);
		int r = moveRight(n - 1);

		if (l < r) {
			result += l;
		}
		else {
			result += r;
		}

		picked++;

		q[n - 1] = 1;

		if (picked == M) break;

		pickPoint = n;
		findPoint();
	}

	printf("%d\n", result);
}
