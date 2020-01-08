#include <iostream>
using namespace std;

int q[10000][2];
int front = -1;
int rear = -1;

void enQueue(int x, int y)
{
	rear++;
	q[rear % 10000][0] = x;
	q[rear % 10000][1] = y;
}

void deQueue()
{
	front++;
}

void createQueue()
{
	front = rear = -1;
}

bool isEmpty()
{
	return front == rear;
}

int n, m;
int arr[102][102] = { {0,} };
int dist[102][102] = { {0,} };
bool visited[102][102] = { {false,}, };


int bfs(int x, int y)
{
	enQueue(x, y);
	dist[x][y] = 1;
	visited[x][y] = true;

	while (!isEmpty())
	{
		int tx = q[front + 1][0];
		int ty = q[front + 1][1];
		deQueue();
		if (arr[tx - 1][ty] == 1)
		{
			if (!visited[tx - 1][ty])
			{
				enQueue(tx - 1, ty);
				dist[tx - 1][ty] = dist[tx][ty] + 1;
				visited[tx - 1][ty] = true;
				if (tx - 1 == n && ty == m) break;
			}
		}
		if (arr[tx + 1][ty] == 1)
		{
			if (!visited[tx + 1][ty])
			{
				enQueue(tx + 1, ty);
				dist[tx + 1][ty] = dist[tx][ty] + 1;
				visited[tx + 1][ty] = true;
				if (tx + 1 == n && ty == m) break;
			}
		}
		if (arr[tx][ty + 1] == 1)
		{
			if (!visited[tx][ty + 1])
			{
				enQueue(tx, ty + 1);
				dist[tx][ty + 1] = dist[tx][ty] + 1;
				visited[tx][ty + 1] = true;
				if (tx == n && ty + 1 == m) break;
			}
		}
		if (arr[tx][ty - 1] == 1)
		{
			if (!visited[tx][ty - 1])
			{
				enQueue(tx, ty - 1);
				dist[tx][ty - 1] = dist[tx][ty] + 1;
				visited[tx][ty - 1] = true;
				if (tx == n && ty - 1 == m) break;
			}
		}
	}
	return dist[n][m];
}

int main()
{
	scanf("%d %d", &n, &m);
	char c;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	cout << bfs(1, 1) << endl;
	return 0;
}
