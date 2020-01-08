#include <iostream>
#include <string>
using namespace std;

int map[51][51];
int visited[51][51];
int m, n, k;
int cnt;
int qx[1000];
int qy[1000];
int front, rear;
int mx[4] = { -1,0,1,0 };
int my[4] = { 0,1,0,-1 };

void push(int x, int y) {
	int r = rear % 1000;
	rear++;
	qx[r] = x;
	qy[r] = y;
}

int pop_x() {
	int f = front % 1000;
	return qx[f];
}

int pop_y() {
	int f = front % 1000;
	front++;
	return qy[f];
}

void BFS(int x, int y) {
	push(x, y);
	visited[x][y] = true;
	while (front != rear) {
		int vx = pop_x();
		int vy = pop_y();
		if (vx + mx[0] > -1) {
			if (map[vx + mx[0]][vy] == 1 && !visited[vx + mx[0]][vy]) {
				visited[vx + mx[0]][vy] = true;
				push(vx + mx[0], vy);
			}
		}
		if (vy + my[1] < m) {
			if (map[vx][vy + my[1]] == 1 && !visited[vx][vy + my[1]]) {
				visited[vx][vy+ my[1]] = true;
				push(vx, vy + my[1]);
			}
		}
		if (vx + mx[2] < n) {
			if (map[vx + mx[2]][vy] == 1 && !visited[vx + mx[2]][vy]) {
				visited[vx + mx[2]][vy] = true;
				push(vx + mx[2], vy);
			}
		}
		if (vy + my[3] > -1) {
			if (map[vx][vy + my[3]] == 1 && !visited[vx][vy + my[3]]) {
				visited[vx][vy + my[3]] = true;
				push(vx, vy + my[3]);
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) 
	{
		cnt = 0;
		front = 0, rear = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < 51; i++)
			for (int j = 0; j < 51; j++)
				visited[i][j] = false;

		for (int i = 0; i < 51; i++)
			for (int j = 0; j < 51; j++)
				map[i][j] = 0;

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 1 && !visited[i][j]) {
					BFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl ;
	}
}
