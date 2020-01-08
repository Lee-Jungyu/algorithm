#include <iostream>
using namespace std;

int N, M;
bool map[1001][1001];
int cnt[1001][1001][2];
int q[1000000][3];
int front, rear;
int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

void push(int x, int y, int b)
{
	q[front % 1000000][0] = x;
	q[front % 1000000][1] = y;
	q[front % 1000000][2] = b;
	front++;
}

void pop()
{
	rear++;
}

int bfs()
{
	push(0, 0, map[0][0]);
	cnt[0][0][map[0][0]] = 1;

	while (front != rear)
	{
		int X = q[rear % 1000000][0];
		int Y = q[rear % 1000000][1];
		int B = q[rear % 1000000][2];
		int count = cnt[X][Y][B];
		if (X == N - 1 && Y == M - 1) {
			return count;
		}
		pop();

		for (int i = 0; i < 4; i++)
		{
			int x = X + mx[i];
			int y = Y + my[i];

			if (x >= 0 && x < N && y >= 0 && y < M)
			{
				if (map[x][y] == 0 && !cnt[x][y][B]) {
					push(x, y, B);
					cnt[x][y][B] = count + 1;
				}

				if (map[x][y] == 1 && !B && !cnt[x][y][1]) {
					push(x, y, 1);
					cnt[x][y][1] = count + 1;
				}
			}
		}
	}

	return -1;
}

int main()
{
	front = rear = 0;

	//input
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		char str[1001];
		scanf("%s", str);
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	printf("%d\n", bfs());
}
