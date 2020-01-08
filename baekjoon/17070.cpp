#include <iostream>
using namespace std;

int N;
int map[17][17];
int mx[3] = { 0,1,1 };
int my[3] = { 1,1,0 };
int q[10000000][3]; //0: row 1: col 2: state
int front, rear;

void input()
{
	front = rear = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

void push(int x, int y, int t)
{
	q[front % 10000000][0] = x;
	q[front % 10000000][1] = y;
	q[front % 10000000][2] = t;
	front++;
}

void pop()
{
	rear++;
}

int solve()
{
	int result = 0;

	push(0, 0, 0);

	while (front != rear) {
		int t = q[rear % 10000000][2];

		int x = q[rear % 10000000][0] + mx[t];
		int y = q[rear % 10000000][1] + my[t];

		pop();

		if (x == N - 1 && y == N - 1) {
			result++;
			continue;
		}

		for (int i = 0; i < 3; i++)
		{
			int X = x + mx[i];
			int Y = y + my[i];

			if (X < N && Y < N) {
				if ((t == 2 && i == 0) || (t == 0 && i == 2)) continue;

				if (i == 0 || i == 2) {
					if (map[X][Y] == 0) {
						push(x, y, i);
					}
				}
				if (i == 1) {
					if (map[X][Y] == 0 && map[X - 1][Y] == 0 && map[X][Y - 1] == 0) {
						push(x, y, i);
					}
				}
			}
		}

	}

	return result;
}

void output()
{
	int result = solve();
	printf("%d\n", result);
}
int main()
{
	input();
	output();
}
