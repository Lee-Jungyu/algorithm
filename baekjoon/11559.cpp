#include <iostream>
#include <string>
#define FAST_IO cin.tie(0); ios_base::sync_with_stdio(false);
using namespace std;

bool visited[13][7] = { {false,}, };
char map[13][7];
int result = 0;
int q[100001][2];
int front, rear;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input()
{
	string str;
	for (int i = 0; i < 12; i++)
	{
		cin >> str;
		for (int j = 0; j < 6; j++)
		{
			map[i][j] = str[j];
		}
	}
}

bool checkMap(int x, int y)
{
	if (x >= 0 && x < 12 && y >= 0 && y < 6) return true;
	return false;
}

bool pang(int x, int y)
{
	int cnt = 0;
	char c = map[x][y];

	q[rear][0] = x;
	q[rear][1] = y;
	rear++;
	visited[x][y] = true;
	cnt++;

	while (front != rear) {
		int xx = q[front][0];
		int yy = q[front][1];
		front++;

		for (int i = 0; i < 4; i++)
		{
			int xxx = xx + dx[i];
			int yyy = yy + dy[i];

			if (checkMap(xxx, yyy)) {
				if (!visited[xxx][yyy] && map[xxx][yyy] == c) {
					q[rear][0] = xxx;
					q[rear][1] = yyy;
					rear++;
					visited[xxx][yyy] = true;
					cnt++;
				}
			}
		}
	}

	if (cnt > 3) {
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (visited[i][j]) {
					map[i][j] = '.';
					visited[i][j] = false;
				}
			}
		}
		return true;
	}
	else {
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (visited[i][j]) {
					visited[i][j] = false;
				}
			}
		}
		return false;
	}

}

void gravity()
{
	for (int j = 0; j < 6; j++)
	{
		string str = "";
		for (int i = 11; i >= 0; i--)
		{
			if (map[i][j] != '.') str += map[i][j];
		}


		for (int i = 11, icnt = 0; icnt < str.length(); i--, icnt++)
		{
			map[i][j] = str[icnt];
		}

		for (int i = 0; i < 12 - str.length(); i++) {
			map[i][j] = '.';
		}
	}
}

void solve()
{
	while (true) {
		bool isChanged = false;
		bool tmp;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (map[i][j] != '.') {
					tmp = pang(i, j);
					if (tmp) {
						isChanged = true;
					}
				}
			}
		}
		gravity();
		if (!isChanged) break;
		result++;
	}
}

void output()
{
	cout << result << '\n';
}


int main()
{
	FAST_IO;
	front = rear = 0;

	input();
	solve();
	output();
}
