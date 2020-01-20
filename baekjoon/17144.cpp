#include <iostream>
using namespace std;

int R, C, T;
int map[51][51];
int tmpmap[51][51];
int airfresher[2];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void input()
{
	int airCnt = 0;
	scanf("%d %d %d", &R, &C, &T);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) {
				airfresher[airCnt] = i;
				airCnt++;
			}
		}
	}
}

bool checkMap(int x, int y)
{
	if (x >= 0 && x < R && y >= 0 && y < C) return true;
	return false;
}

void spread()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++) {
			if (map[i][j] == -1) tmpmap[i][j] = -1;
			else tmpmap[i][j] = 0;
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] != 0 && map[i][j] != -1) {
				int validCnt = 0;
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];

					if (checkMap(x,y) && map[x][y] != -1) {
						validCnt++;
						tmpmap[x][y] += map[i][j] / 5;
					}
				}
				tmpmap[i][j] += map[i][j] - (validCnt) * (map[i][j] / 5);
			}
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			map[i][j] = tmpmap[i][j];
		}
	}
}

void blow()
{
	for (int i = airfresher[0] - 1; i > 0; i--) {
		map[i][0] = map[i - 1][0];
	}
	for (int i = airfresher[1] + 1; i < R - 1; i++) {
		map[i][0] = map[i + 1][0];
	}
	for (int j = 0; j < C - 1; j++) {
		map[0][j] = map[0][j + 1];
		map[R - 1][j] = map[R - 1][j + 1];
	}
	for (int i = 0; i < airfresher[0]; i++) {
		map[i][C - 1] = map[i + 1][C - 1];
	}
	for (int i = R - 1; i > airfresher[1]; i--) {
		map[i][C - 1] = map[i - 1][C - 1];
	}
	for (int j = C - 1; j > 1; j--) {
		map[airfresher[0]][j] = map[airfresher[0]][j - 1];
		map[airfresher[1]][j] = map[airfresher[1]][j - 1];
	}
	map[airfresher[0]][1] = 0;
	map[airfresher[1]][1] = 0;
}

void solve()
{
	for (int i = 0; i < T; i++)
	{
		spread();
		blow();
	}
}

void output()
{
	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != -1) {
				sum += map[i][j];
			}
		}
	}

	printf("%d\n", sum);
}

int main()
{
	input();
	solve();
	output();
}
