#include <iostream>
using namespace std;

int map[50][50];
bool visited[50][50];
int w, h;
int cnt;
int qx[10000];
int qy[10000];
int front;
int rear;

void push(int x, int y)
{
	int r = rear % 10000;
	qx[r] = x;
	qy[r] = y;
	rear++;
}

int pop_x()
{
	int fx = front % 10000;
	return qx[fx];
}

int pop_y()
{
	int ry = front % 10000;
	front++;
	return qy[ry];
}/*
int x[4] = { -1, 1, 0, 0 };
int y[4] = {}*/
void BFS(int x, int y)
{
	visited[x][y] = true;
	push(x, y);
	while (front != rear) {
		int vx = pop_x();
		int vy = pop_y();
		//cout << vx << " " << vy << endl;
		if (vx > 0 && vy > 0)
			if (!visited[vx - 1][vy - 1] && map[vx - 1][vy - 1] == 1)
			{
				push(vx - 1, vy - 1);
				visited[vx - 1][ vy - 1] = true;
			}
		if (vx > 0 && vy < w - 1)
			if (!visited[vx - 1][vy + 1] && map[vx - 1][vy + 1] == 1)
			{
				push(vx - 1, vy + 1);
				visited[vx - 1][vy + 1] = true;
			}
		if (vx < h - 1 && vy > 0)
			if (!visited[vx + 1][vy - 1] && map[vx + 1][vy - 1] == 1)
			{
				push(vx + 1, vy - 1);
				visited[vx + 1][vy - 1] = true;
			}
		if (vx < h - 1 && vy < w - 1)
			if (!visited[vx + 1][vy + 1] && map[vx + 1][vy + 1] == 1)
			{
				push(vx + 1, vy + 1);
				visited[vx + 1][vy + 1] = true;
			}
		if (vx > 0)
			if (!visited[vx - 1][vy] && map[vx - 1][vy] == 1)
			{
				push(vx - 1, vy);
				visited[vx - 1][vy] = true;
			}
		if (vx < h - 1)
			if (!visited[vx + 1][vy] && map[vx + 1][vy] == 1)
			{
				push(vx + 1, vy);
				visited[vx + 1][vy] = true;
			}
		if (vy > 0)
			if (!visited[vx][vy - 1] && map[vx][vy - 1] == 1)
			{
				push(vx, vy - 1);
				visited[vx][vy - 1] = true;
			}
		if (vy < w - 1)
			if (!visited[vx][vy + 1] && map[vx][vy + 1] == 1)
			{
				push(vx, vy + 1);
				visited[vx][vy + 1] = true;
			}
		
	}
}

int main()
{
	do {
		cnt = 0;
		front = 0;
		rear = 0;

		cin >> w >> h;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				visited[i][j] = false;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					cnt++;
					BFS(i, j);
				}
			}

		if (w != 0 || h != 0)
			cout << cnt << endl;

	} while (w != 0 || h != 0);
}
