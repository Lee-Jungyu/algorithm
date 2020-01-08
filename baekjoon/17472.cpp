#include <iostream>
using namespace std;

int N, M, result, islandCnt, edgeCnt;
int map[11][11];
int dist[7][7];
int edge[1000][3]; // s, d, l
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

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

void checkIsland()
{
	islandCnt = 0;
	int q[1000][2];
	int front, rear;
	front = rear = 0;

	
	bool visitedmap[11][11] = { {false,}, };

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] != 0 && !visitedmap[i][j]) {
				islandCnt++;

				q[front % 1000][0] = i;
				q[front % 1000][1] = j;
				front++;

				while (front != rear) {
					int a = q[rear][0];
					int b = q[rear][1];
					rear++;

					visitedmap[a][b] = true;
					map[a][b] = islandCnt;

					for (int k = 0; k < 4; k++)
					{
						int c = a + dx[k];
						int d = b + dy[k];
						if (c >= 0 && c < N && d >= 0 && d < M)
						{
							if (map[c][d] != 0 && !visitedmap[c][d])
							{
								q[front % 1000][0] = c;
								q[front % 1000][1] = d;
								front++;
							}
						}
					}
				}
			}
		}
	}
}

bool checkBorder(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M)
		{
			if (map[x + dx[i]][y + dy[i]] == 0) {
				return true;
			}
		}
	}

	return false;
}

int getMinDist(int s, int d)
{
	int minDist = 999;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == s && checkBorder(i,j)) {
				//dfs로 d지점 찾기
				for (int k = 0; k < 4; k++)
				{
					int mdist = 0;

					int a = i + dx[k];
					int b = j + dy[k];

					while (a >= 0 && a < N && b >= 0 && b < M) {
						
						if (map[a][b] != 0 && map[a][b] != d) break;
						mdist++;

						if (map[a][b] == d && checkBorder(a, b))
						{
							if (mdist > 2 && minDist > mdist) {
								minDist = mdist;
							}
							break;
						}

						a += dx[k];
						b += dy[k];
					}
				}
			}
		}
	}

	if (minDist == 999) return 0;
	return minDist - 1;
}

void getDist()
{
	edgeCnt = 0;
	for (int i = 1; i <= islandCnt; i++)
	{
		for (int j = 1; j <= islandCnt; j++)
		{
			if (i != j && dist[i][j] == 0) {
				dist[i][j] = dist[j][i] = getMinDist(i, j);
				if (dist[i][j] != 0) 
				{
					edge[edgeCnt][0] = i;
					edge[edgeCnt][1] = j;
					edge[edgeCnt][2] = dist[i][j];
					edgeCnt++;
				}
			}
		}
	}
}

int kruscal()
{
	int parent[7];
	int sum = 0;

	for (int i = 1; i <= islandCnt; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < edgeCnt - 1; i++)
	{
		int k = i;
		for (int j = k; j < edgeCnt; j++)
		{
			if (edge[i][2] > edge[j][2])
			{
				for (int l = 0; l < 3; l++)
				{
					int tmp = edge[i][l];
					edge[i][l] = edge[j][l];
					edge[j][l] = tmp;
				}
			}
		}
	}

	for (int i = 0; i < edgeCnt; i++)
	{
		int a = edge[i][0];
		int b = edge[i][1];
		if (parent[a] != parent[b])
		{
			sum += edge[i][2];
			if (parent[a] < parent[b]) {
				int tmp = parent[b];
				for (int j = 1; j <= islandCnt; j++) {
					if (parent[j] == tmp) parent[j] = parent[a];
				}
			}

			else {
				int tmp = parent[a];
				for (int j = 1; j <= islandCnt; j++) {
					if (parent[j] == tmp) parent[j] = parent[b];
				}
			}

		}
	}

	for (int i = 1; i <= islandCnt; i++)
	{
		if (parent[i] != 1) return -1;
	}
	return sum;
}

void solve()
{
	checkIsland();
	getDist();
	
	result = kruscal();
}

void output()
{
	printf("%d\n", result);
}

int main()
{
	input();
	solve();
	output();
}
