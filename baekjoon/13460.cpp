#include <iostream>
using namespace std;

int N, M;
int result = 999;
char firstMap[11][11];
char map[11][11][11];

void input()
{
	char str[11];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		for (int j = 0; j < M; j++)
		{
			firstMap[i][j] = str[j];
		}
	}
}

int left(int count)
{
	int RX = 0, RY = 0, BX = 0, BY = 0;
	int checkRB = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[count][i][j] == 'R') {
				RX = i; RY = j;
				for (int k = j + 1; k < M; k++) {
					if (map[count][i][k] == 'B') {
						BX = i; BY = k;
						checkRB = 1;
						break;
					}
				}
			}
			if (map[count][i][j] == 'B') {
				BX = i; BY = j;
				for (int k = j + 1; k < M; k++) {
					if (map[count][i][k] == 'R') {
						RX = i, RY = k;
						checkRB = 2;
						break;
					}
				}
			}
			if (checkRB) break;
		}
		if (checkRB) break;
	}
	int redGoal = 0;
	int blueGoal = 0;

	if (checkRB == 1) {
		for (int j = RY - 1; j >= 0; j--)
		{
			if (map[count][RX][j] != '.') {
				if (map[count][RX][j] == 'O') {
					map[count][RX][RY] = '.';
					redGoal = 1;
				}
				else {
					map[count][RX][RY] = '.';
					map[count][RX][j + 1] = 'R';
				}
				break;
			}
		}
		for (int j = BY - 1; j >= 0; j--)
		{
			if (map[count][BX][j] != '.') {
				if (map[count][BX][j] == 'O') {
					map[count][BX][BY] = '.';
					blueGoal = 1;
				}
				else {
					map[count][BX][BY] = '.';
					map[count][BX][j + 1] = 'B';
				}
				break;
			}
		}
	}

	else {
		for (int j = BY - 1; j >= 0; j--)
		{
			if (map[count][BX][j] != '.') {
				if (map[count][BX][j] == 'O') {
					map[count][BX][BY] = '.';
					blueGoal = 1;
				}
				else {
					map[count][BX][BY] = '.';
					map[count][BX][j + 1] = 'B';
				}
				break;
			}
		}

		for (int j = RY - 1; j >= 0; j--)
		{
			if (map[count][RX][j] != '.') {
				if (map[count][RX][j] == 'O') {
					map[count][RX][RY] = '.';
					redGoal = 1;
				}
				else {
					map[count][RX][RY] = '.';
					map[count][RX][j + 1] = 'R';
				}
				break;
			}
		}
	}

	if (blueGoal) return 2;
	if (redGoal) return 1;

	return 0;
}

int right(int count)
{
	int RX, RY, BX, BY;
	int checkRB = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[count][i][j] == 'R') {
				RX = i; RY = j;
				for (int k = j + 1; k < M; k++) {
					if (map[count][i][k] == 'B') {
						BX = i; BY = k;
						checkRB = 2;
						break;
					}
				}
			}
			if (map[count][i][j] == 'B') {
				BX = i; BY = j;
				for (int k = j + 1; k < M; k++) {
					if (map[count][i][k] == 'R') {
						RX = i, RY = k;
						checkRB = 1;
						break;
					}
				}
			}
			if (checkRB) break;
		}
		if (checkRB) break;
	}

	int redGoal = 0;
	int blueGoal = 0;
	if (checkRB == 1) {
		for (int j = RY + 1; j < M; j++)
		{
			if (map[count][RX][j] != '.') {
				if (map[count][RX][j] == 'O') {
					map[count][RX][RY] = '.';
					redGoal = 1;
				}
				else {
					map[count][RX][RY] = '.';
					map[count][RX][j - 1] = 'R';
				}
				break;
			}
		}

		for (int j = BY + 1; j < M; j++)
		{
			if (map[count][BX][j] != '.') {
				if (map[count][BX][j] == 'O') {
					map[count][BX][BY] = '.';
					blueGoal = 1;
				}
				else {
					map[count][BX][BY] = '.';
					map[count][BX][j - 1] = 'B';
				}
				break;
			}
		}
	}

	else {
		for (int j = BY + 1; j < M; j++)
		{
			if (map[count][BX][j] != '.') {
				if (map[count][BX][j] == 'O') {
					map[count][BX][BY] = '.';
					blueGoal = 1;
				}
				else {
					map[count][BX][BY] = '.';
					map[count][BX][j - 1] = 'B';
				}
				break;
			}
		}

		for (int j = RY + 1; j < M; j++)
		{
			if (map[count][RX][j] != '.') {
				if (map[count][RX][j] == 'O') {
					map[count][RX][RY] = '.';
					redGoal = 1;
				}
				else {
					map[count][RX][RY] = '.';
					map[count][RX][j - 1] = 'R';
				}
				break;
			}
		}
	}

	if (blueGoal) return 2;
	if (redGoal) return 1;


	return 0;
}

int up(int count)
{
	int RX, RY, BX, BY;
	int checkRB = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[count][i][j] == 'R') {
				RX = i; RY = j;
				for (int k = i + 1; k < N; k++) {
					if (map[count][k][j] == 'B') {
						BX = k; BY = j;
						checkRB = 1;
						break;
					}
				}
			}
			if (map[count][i][j] == 'B') {
				BX = i; BY = j;
				for (int k = i + 1; k < N; k++) {
					if (map[count][k][j] == 'R') {
						RX = k, RY = j;
						checkRB = 2;
						break;
					}
				}
			}
			if (checkRB) break;
		}
		if (checkRB) break;
	}

	int redGoal = 0;
	int blueGoal = 0;
	if (checkRB == 1) {
		for (int i = RX - 1; i >= 0; i--)
		{
			if (map[count][i][RY] != '.') {
				if (map[count][i][RY] == 'O') {
					map[count][RX][RY] = '.';
					redGoal = 1;
				}
				else {
					map[count][RX][RY] = '.';
					map[count][i + 1][RY] = 'R';
				}
				break;
			}
		}

		for (int i = BX - 1; i >= 0; i--)
		{
			if (map[count][i][BY] != '.') {
				if (map[count][i][BY] == 'O') {
					map[count][BX][BY] = '.';
					blueGoal = 1;
				}
				else {
					map[count][BX][BY] = '.';
					map[count][i + 1][BY] = 'B';
				}
				break;
			}
		}
	}

	else {
		for (int i = BX - 1; i >= 0; i--)
		{
			if (map[count][i][BY] != '.') {
				if (map[count][i][BY] == 'O') {
					map[count][BX][BY] = '.';
					blueGoal = 1;
				}
				else {
					map[count][BX][BY] = '.';
					map[count][i + 1][BY] = 'B';
				}
				break;
			}
		}

		for (int i = RX - 1; i >= 0; i--)
		{
			if (map[count][i][RY] != '.') {
				if (map[count][i][RY] == 'O') {
					map[count][RX][RY] = '.';
					redGoal = 1;
				}
				else {
					map[count][RX][RY] = '.';
					map[count][i + 1][RY] = 'R';
				}
				break;
			}
		}
	}
	if (blueGoal) return 2;
	if (redGoal) return 1;

	return 0;
}

int down(int count)
{

	int RX, RY, BX, BY;
	int checkRB = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[count][i][j] == 'R') {
				RX = i; RY = j;
				for (int k = i + 1; k < N; k++) {
					if (map[count][k][j] == 'B') {
						BX = k; BY = j;
						checkRB = 2;
						break;
					}
				}
			}
			if (map[count][i][j] == 'B') {
				BX = i; BY = j;
				for (int k = i + 1; k < N; k++) {
					if (map[count][k][j] == 'R') {
						RX = k, RY = j;
						checkRB = 1;
						break;
					}
				}
			}
			if (checkRB) break;
		}
		if (checkRB) break;
	}

	bool redGoal = 0;
	bool blueGoal = 0;
	if (checkRB == 1) {
		for (int i = RX + 1; i < N; i++)
		{
			if (map[count][i][RY] != '.') {
				if (map[count][i][RY] == 'O') {
					map[count][RX][RY] = '.';
					redGoal = 1;
				}
				else {
					map[count][RX][RY] = '.';
					map[count][i - 1][RY] = 'R';
				}
				break;
			}
		}

		for (int i = BX + 1; i < N; i++)
		{
			if (map[count][i][BY] != '.') {
				if (map[count][i][BY] == 'O') {
					map[count][BX][BY] = '.';
					blueGoal = 1;
				}
				map[count][BX][BY] = '.';
				map[count][i - 1][BY] = 'B';
				break;
			}
		}

	}

	else {
		for (int i = BX + 1; i < N; i++)
		{
			if (map[count][i][BY] != '.') {
				if (map[count][i][BY] == 'O') {
					map[count][BX][BY] = '.';
					blueGoal = 1;
				}
				else {
					map[count][BX][BY] = '.';
					map[count][i - 1][BY] = 'B';
				}
				break;
			}
		}

		for (int i = RX + 1; i < N; i++)
		{
			if (map[count][i][RY] != '.') {
				if (map[count][i][RY] == 'O') {
					map[count][RX][RY] = '.';
					redGoal = 1;
				}
				else {
					map[count][RX][RY] = '.';
					map[count][i - 1][RY] = 'R';
				}
				break;
			}
		}
	}
	if (blueGoal) return 2;
	if (redGoal) return 1;

	return 0;
}

void dfs(int count, int direction)
{
	int problem = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map[count][i][j] = map[count - 1][i][j];
		}
	}

	switch (direction)
	{
	case 1:
		problem = left(count);
		break;
	case 2:
		problem = right(count);
		break;
	case 3:
		problem = up(count);
		break;
	case 4:
		problem = down(count);
		break;
	default:
		break;
	}

	if (problem) {
		if (problem == 1) {
			if (result > count) {
				result = count;
				return;
			}
		}
		//문제가 생겼을 경우
		return;
	}

	if (count == 10) {

		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		if (result == 1) return;
		dfs(count + 1, i);
	}

}

void solve()
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++)
		{
			map[0][i][j] = firstMap[i][j];
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		dfs(1, i);
	}
}

void output()
{
	if (result == 999) printf("-1\n");
	else printf("%d\n", result);
}

int main()
{
	input();
	solve();
	output();

}
