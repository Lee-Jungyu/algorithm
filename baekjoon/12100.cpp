#include <iostream>
using namespace std;

int N, result;
int map[21][21];
int currmap[6][21][21];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

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

void move(int cnt, int t)
{
	bool hitmap[21][21] = { {false,}, };
	
	switch (t)
	{
	case 0:
		//left();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (currmap[cnt + 1][i][j] != 0) {
					int point = currmap[cnt + 1][i][j];

					for (int k = 1; k < N; k++) {
						int a = i + k * dx[t];
						int b = j + k * dy[t];

						if (a >= 0 && a < N && b >= 0 && b < N)
						{
							if (currmap[cnt + 1][a][b] != 0) {
								if (currmap[cnt + 1][a][b] == point && !hitmap[a][b]) {
									currmap[cnt + 1][i][j] = 0;
									currmap[cnt + 1][a][b] = 2 * point;
									hitmap[a][b] = true;
								}
								else {
									break;
								}
							}
						}
						else {
							break;
						}
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (currmap[cnt + 1][i][j] != 0)
				{
					int a = i + dx[t];
					int b = j + dy[t];

					while (a >= 0 && a < N && b >= 0 && b < N) {
						if (currmap[cnt + 1][a][b] == 0) {
							currmap[cnt + 1][a][b] = currmap[cnt + 1][a - dx[t]][b - dy[t]];
							currmap[cnt + 1][a - dx[t]][b - dy[t]] = 0;
						}

						a += dx[t];
						b += dy[t];
					}
				}
			}
		}
		
		break;
	case 1:
		//right();
		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >= 0; j--)
			{
				if (currmap[cnt + 1][i][j] != 0) {
					int point = currmap[cnt + 1][i][j];

					for (int k = 1; k < N; k++) {
						int a = i + k * dx[t];
						int b = j + k * dy[t];

						if (a >= 0 && a < N && b >= 0 && b < N)
						{
							if (currmap[cnt + 1][a][b] != 0) {
								if (currmap[cnt + 1][a][b] == point && !hitmap[a][b]) {
									currmap[cnt + 1][i][j] = 0;
									currmap[cnt + 1][a][b] = 2 * point;
									hitmap[a][b] = true;
								}
								else {
									break;
								}
							}
						}
						else {
							break;
						}
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >= 0; j--)
			{
				if (currmap[cnt + 1][i][j] != 0)
				{
					int point = currmap[cnt + 1][i][j];
					int a = i + dx[t];
					int b = j + dy[t];
					while (a >= 0 && a < N && b >= 0 && b < N) {
						if (currmap[cnt + 1][a][b] == 0) {
							currmap[cnt + 1][a][b] = currmap[cnt + 1][a - dx[t]][b - dy[t]];
							currmap[cnt + 1][a - dx[t]][b - dy[t]] = 0;
						}

						a += dx[t];
						b += dy[t];
					}
				}
			}
		}
		break;
	case 2:
		//up();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (currmap[cnt + 1][i][j] != 0) {
					int point = currmap[cnt + 1][i][j];

					for (int k = 1; k < N; k++) {
						int a = i + k * dx[t];
						int b = j + k * dy[t];

						if (a >= 0 && a < N && b >= 0 && b < N)
						{
							if (currmap[cnt + 1][a][b] != 0) {
								if (currmap[cnt + 1][a][b] == point && !hitmap[a][b]) {
									currmap[cnt + 1][i][j] = 0;
									currmap[cnt + 1][a][b] = 2 * point;
									hitmap[a][b] = true;
								}
								else {
									break;
								}
							}
						}
						else {
							break;
						}
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (currmap[cnt + 1][i][j] != 0)
				{
					int a = i + dx[t];
					int b = j + dy[t];

					while (a >= 0 && a < N && b >= 0 && b < N) {
						if (currmap[cnt + 1][a][b] == 0) {
							currmap[cnt + 1][a][b] = currmap[cnt + 1][a - dx[t]][b - dy[t]];
							currmap[cnt + 1][a - dx[t]][b - dy[t]] = 0;
						}

						a += dx[t];
						b += dy[t];
					}
				}
			}
		}

		break;
	case 3:
		//down();
		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j < N; j++)
			{
				if (currmap[cnt + 1][i][j] != 0) {
					int point = currmap[cnt + 1][i][j];

					for (int k = 1; k < N; k++) {
						int a = i + k * dx[t];
						int b = j + k * dy[t];

						if (a >= 0 && a < N && b >= 0 && b < N)
						{
							if (currmap[cnt + 1][a][b] != 0) {
								if (currmap[cnt + 1][a][b] == point && !hitmap[a][b]) {
									currmap[cnt + 1][i][j] = 0;
									currmap[cnt + 1][a][b] = 2 * point;
									hitmap[a][b] = true;
								}
								else {
									break;
								}
							}
						}
						else {
							break;
						}
					}
				}
			}
		}

		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j < N; j++)
			{
				if (currmap[cnt + 1][i][j] != 0)
				{
					int a = i + dx[t];
					int b = j + dy[t];

					while (a >= 0 && a < N && b >= 0 && b < N) {
						if (currmap[cnt + 1][a][b] == 0) {
							currmap[cnt + 1][a][b] = currmap[cnt + 1][a - dx[t]][b - dy[t]];
							currmap[cnt + 1][a - dx[t]][b - dy[t]] = 0;
						}

						a += dx[t];
						b += dy[t];
					}
				}
			}
		}
		break;
	}
}

void dfs(int cnt, int t)
{
	if (cnt == 5) {
		int max = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (max < currmap[cnt][i][j]) max = currmap[cnt][i][j];
			}
		}

		if (result < max) result = max;

		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			currmap[cnt + 1][i][j] = currmap[cnt][i][j];
		}
	}

	move(cnt, t);

	for (int i = 0; i < 4; i++)
	{
		dfs(cnt + 1, i);
	}
}

void solve()
{
	for (int t = 0; t < 4; t++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				currmap[0][i][j] = map[i][j];
			}
		}

		dfs(0, t);
	}

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

