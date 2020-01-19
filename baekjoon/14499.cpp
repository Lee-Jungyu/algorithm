#include <iostream>
using namespace std;

int N, M; //N:row M:col
int x, y; //(x, y)point of dice location
int K; //command cnt
int map[21][21];
int cmd[1001]; //command array
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int dice[6] = { 0, };
int currDiceFace = 0;

void input()
{
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (int k = 0; k < K; k++)
	{
		scanf("%d", &cmd[k]);
	}
}

bool checkMap(int i, int j)
{
	if (i >= 0 && i < N && j >= 0 && j < M) return true;
	return false;
}

void rollDice(int dir)
{
	int d[6];
	for (int i = 0; i < 6; i++)
	{
		d[i] = dice[i];
	}

	//E 
	//012345
	//310542
	if (dir == 0) {
		dice[0] = d[3];
		dice[2] = d[0];
		dice[3] = d[5];
		dice[5] = d[2];
	}

	//W
	//012345
	//215043
	else if (dir == 1) {
		dice[0] = d[2];
		dice[2] = d[5];
		dice[3] = d[0];
		dice[5] = d[3];
	}

	//N
	//012345
	//402351
	else if (dir == 2) {
		dice[0] = d[4];
		dice[1] = d[0];
		dice[4] = d[5];
		dice[5] = d[1];
	}

	//S
	//012345
	//152304
	else {
		dice[0] = d[1];
		dice[1] = d[5];
		dice[4] = d[0];
		dice[5] = d[4];
	}
}

void solve()
{
	int dir;
	for (int i = 0; i < K; i++)
	{
		dir = cmd[i] - 1;
		if (checkMap(x + dx[dir], y + dy[dir])) {
			x = x + dx[dir];
			y = y + dy[dir];

			rollDice(dir);
			
			if (map[x][y]) {
				dice[5] = map[x][y];
				map[x][y] = 0;
			}
			else {
				map[x][y] = dice[5];
			}
			printf("%d\n", dice[0]);
		}
	}
}

int main()
{
	input();
	solve();
}
