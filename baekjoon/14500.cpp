#include <iostream>
using namespace std;

int N, M;
int map[501][501];
bool visited[501][501] = { {false,}, };
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int maxSum = 0;

void input()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
}

bool checkMap(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y <= M)
		return true;
	return false;
}

void dfs(int cnt, int x, int y, int sum)
{
	sum += map[x][y];
	if (cnt == 4) {
		if (maxSum < sum) maxSum = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (checkMap(xx, yy)) {
			if (!visited[xx][yy]) {
				visited[xx][yy] = true;
				dfs(cnt + 1, xx, yy, sum);
				visited[xx][yy] = false;
			}
		}
	}
}

void TtypeBlock(int x, int y)
{
	if (checkMap(x + 2 * dx[0], y + 2 * dy[0]))
	{
		if (checkMap(x + dx[0] + dx[1], y + dy[0] + dy[1])) {
			int sum = map[x][y] + map[x + dx[0]][y + dy[0]] + map[x + 2 * dx[0]][y + 2 * dy[0]] + map[x + dx[0] + dx[1]][y + dy[0] + dy[1]];
			if (sum > maxSum) maxSum = sum;
		}
		if (checkMap(x + dx[0] + dx[3], y + dy[0] + dy[3])) {
			int sum = map[x][y] + map[x + dx[0]][y + dy[0]] + map[x + 2 * dx[0]][y + 2 * dy[0]] + map[x + dx[0] + dx[3]][y + dy[0] + dy[3]];
			if (sum > maxSum) maxSum = sum;
		}
	}

	if (checkMap(x + 2 * dx[2], y + 2 * dy[2]))
	{
		if (checkMap(x + dx[2] + dx[1], y + dy[2] + dy[1])) {
			int sum = map[x][y] + map[x + dx[2]][y + dy[2]] + map[x + 2 * dx[2]][y + 2 * dy[2]] + map[x + dx[2] + dx[1]][y + dy[2] + dy[1]];
			if (sum > maxSum) maxSum = sum;
		}
		if (checkMap(x + dx[0] + dx[3], y + dy[0] + dy[3])) {
			int sum = map[x][y] + map[x + dx[2]][y + dy[2]] + map[x + 2 * dx[2]][y + 2 * dy[2]] + map[x + dx[2] + dx[3]][y + dy[2] + dy[3]];
			if (sum > maxSum) maxSum = sum;
		}
	}

	if (checkMap(x + 2 * dx[1], y + 2 * dy[1]))
	{
		if (checkMap(x + dx[1] + dx[0], y + dy[1] + dy[0])) {
			int sum = map[x][y] + map[x + dx[1]][y + dy[1]] + map[x + 2 * dx[1]][y + 2 * dy[1]] + map[x + dx[1] + dx[0]][y + dy[1] + dy[0]];
			if (sum > maxSum) maxSum = sum;
		}
		if (checkMap(x + dx[1] + dx[2], y + dy[1] + dy[2])) {
			int sum = map[x][y] + map[x + dx[1]][y + dy[1]] + map[x + 2 * dx[1]][y + 2 * dy[1]] + map[x + dx[1] + dx[2]][y + dy[1] + dy[2]];
			if (sum > maxSum) maxSum = sum;
		}
	}

	if (checkMap(x + 2 * dx[3], y + 2 * dy[3]))
	{
		if (checkMap(x + dx[3] + dx[0], y + dy[3] + dy[0])) {
			int sum = map[x][y] + map[x + dx[3]][y + dy[3]] + map[x + 2 * dx[3]][y + 2 * dy[3]] + map[x + dx[3] + dx[0]][y + dy[3] + dy[0]];
			if (sum > maxSum) maxSum = sum;
		}
		if (checkMap(x + dx[3] + dx[2], y + dy[3] + dy[2])) {
			int sum = map[x][y] + map[x + dx[3]][y + dy[3]] + map[x + 2 * dx[3]][y + 2 * dy[3]] + map[x + dx[3] + dx[2]][y + dy[3] + dy[2]];
			if (sum > maxSum) maxSum = sum;
		}
	}
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = true;
			dfs(1, i, j, 0);
			TtypeBlock(i, j);
			visited[i][j] = false;
		}
	}
}

void output()
{
	printf("%d\n", maxSum);
}

int main()
{
	input();
	solve();
	output();
}

