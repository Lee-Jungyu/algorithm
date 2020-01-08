#include <iostream>
using namespace std;

int N, M;
int chickenNum;
int minDist = 999999999;
int map[51][51];
int chicken[14][2];
bool visited[14] = { false, };

void input()
{
	int cflag = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				chicken[cflag][0] = i;
				chicken[cflag][1] = j;
				cflag++;
			}
		}
	}

	chickenNum = cflag;
}

int getDist(int r1, int c1, int r2, int c2) {
	int r, c;
	if (r1 < r2) {
		r = r2 - r1;
	}
	else {
		r = r1 - r2;
	}

	if (c1 < c2) {
		c = c2 - c1;
	}
	else {
		c = c1 - c2;
	}

	return r + c;
}

void dfs(int m, int r, int c, int idx) {
	
	if (m == M) {
		int sum = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1) {
					int v = 999999999;
					for (int k = 0; k < chickenNum; k++)
					{
						if (visited[k]) {
							int vv = getDist(i, j, chicken[k][0], chicken[k][1]);
							if (v > vv) v = vv;
						}
					}
					sum += v;
				}
			}
		}

		if (minDist > sum) minDist = sum;
		return;
	}

	for (int i = idx; i < chickenNum; i++)
	{
		if (!visited[i]) {
			visited[i] = true;
			map[chicken[i][0]][chicken[i][1]] = 3;
			dfs(m + 1, chicken[i][0], chicken[i][1], i);
			map[chicken[i][0]][chicken[i][1]] = 2;
			visited[i] = false;
		}
	}
}

void solve()
{
	for (int i = 0; i < chickenNum; i++) {
		visited[i] = true;
		map[chicken[i][0]][chicken[i][1]] = 3;
		dfs(1, chicken[i][0], chicken[i][1], i);
		map[chicken[i][0]][chicken[i][1]] = 2;
		visited[i] = false;
	}
}

void output()
{
	printf("%d\n", minDist);
}

int main()
{
	input();
	solve();
	output();
}
