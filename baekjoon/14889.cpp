#include <iostream>
using namespace std;

int N;
int map[20][20];
int team[20] = { 0, };
int minV = 999999999;

void input()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
}

void output()
{
	printf("%d\n", minV);
}

void solve(int cnt, int n)
{

	if (cnt == N / 2) {
		for (int i = 0; i < N; i++) {
			if (team[i] != 1) {
				team[i] = 2;
			}
		}

		int team1 = 0;
		int team2 = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++) 
			{
				if (team[i] == 1 && team[j] == 1) {
					team1 += map[i][j];
				}
				if (team[i] == 2 && team[j] == 2) {
					team2 += map[i][j];
				}
			}
		}

		int diff = team1 - team2;

		if (diff < 0) diff = -diff;
		if (minV > diff) minV = diff;

		return;
	}

	for (int i = n + 1; i < N; i++) {
    team[i] = 1;
		solve(cnt + 1, i);
		team[i] = 0;
	}
}

int main()
{
	input();
	
	for (int i = 0; i < N / 2 + 1; i++) {
		team[i] = 1;
		solve(1, i);
		team[i] = 0;
	}

	output();
}
