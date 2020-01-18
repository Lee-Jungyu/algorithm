#include <iostream>
using namespace std;

int N, M, D;
int maxKill; //Max Kill Score
int map[16][16]; //real
int board[16][16]; //copy
int ap[16]; //Archer Position
int kill;
int value;

void initialize()
{
	maxKill = -1;
}

void input()
{
	scanf("%d %d %d", &N, &M, &D);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
}

int distance(int r1, int c1, int r2, int c2)
{
	int r, c;

	if (r1 < r2) r = r2 - r1;
	else r = r1 - r2;

	if (c1 < c2) c = c2 - c1;
	else c = c1 - c2;

	return r + c;
}

void attack(int x, int y)
{
	int md = 99, mi = 100, mj = 100;
	int flag = x + 100;

	for (int i = x - 1; i >= 0; i--)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 1 || board[i][j] == flag)
			{
				int dis = distance(x, y, i, j);
				if (D >= dis)
				{
					if (md > dis) {
						md = dis;
						mi = i;
						mj = j;
					}
					if (md == dis) {
						if (mj > j) {
							md = dis;
							mi = i;
							mj = j;
						}
					}
				}
			}
		}
	}

	if (mi != 100 && mj != 100) {
		if (board[mi][mj] != flag) {
			board[mi][mj] = flag;
			kill++;
		}
	}
}

void start()
{
	value = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			board[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		board[N][i] = ap[i];
	}

	int turn = N;
	while (turn) {
		
		for (int i = 0; i < M; i++)
		{
			kill = 0;
			
			if (board[turn][i] == 3) {
				attack(turn, i);
			}
			
			value += kill;
		}
		for (int j = 0; j < M; j++)
		{
			board[turn - 1][j] = board[turn][j];
		}
		turn--;
	}

	if (maxKill < value) maxKill = value;
}

void positioning(int pos, int num)
{
	ap[pos] = 3;

	if (num == 3) {
		start();

		ap[pos] = 0;
		return;
	}

	while (pos < M - 1) {
		pos++;
		positioning(pos, num + 1);
		ap[pos] = 0;
	}

}


void solve()
{
	//궁수위치 정하고
	for (int i = 0; i < M - 2; i++)
	{
		positioning(i, 1);
		ap[i] = 0;
	}

}

void output()
{
	printf("%d\n", maxKill);
}

int main()
{
	initialize();
	input();
	solve();
	output();
}

