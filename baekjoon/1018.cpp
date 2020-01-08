#include <iostream>
using namespace std;

int N, M;
char map[51][51];
int BF[51][51]; //Black First
int WF[51][51]; //White First
int result;

void input()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}
}

void solve()
{
	int min = 999999999;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((i + j) % 2 == 0) {
				//BF
				if (map[i][j] != 'B') {
					BF[i][j]++;
				}
				//WF
				if (map[i][j] != 'W') {
					WF[i][j]++;
				}
			}

			else {
				//BF
				if (map[i][j] != 'W') {
					BF[i][j]++;
				}
				//WF
				if (map[i][j] != 'B') {
					WF[i][j]++;
				}
			}
		}
	}

	int bCnt = 0;
	int wCnt = 0;

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			for (int y = i; y < i + 8; y++)
			{
				for (int x = j; x < j + 8; x++)
				{
					if (BF[y][x]) {
						bCnt++;
					}
					if (WF[y][x]) {
						wCnt++;
					}
				}
			}

			if (bCnt < wCnt) {
				if (bCnt < min) {
					min = bCnt;
				}
			}
			else {
				if (wCnt < min) {
					min = wCnt;
				}
			}

			bCnt = 0;
			wCnt = 0;
		}
	}

	result = min;
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
