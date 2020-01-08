#include <iostream>
using namespace std;

int map[9][9];
int zeroCnt = 0;

void input()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
				zeroCnt++;
		}
	}
}

void output()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}

void solve(int x, int y) {

	//output();

	if (zeroCnt == 0) {
		return;
	}

	bool impossible[10] = { false, };

	for (int i = 0; i < 9; i++)
	{
		//vertical check
		if (map[i][y] != 0) {
			impossible[map[i][y]] = true;
		}

		//horizontal check
		if (map[x][i] != 0) {
			impossible[map[x][i]] = true;
		}
	}

	//square check
	for (int i = x - x % 3; i < x - x % 3 + 3; i++)
	{
		for (int j = y - y % 3; j < y - y % 3 + 3; j++)
		{
			if (map[i][j] != 0) {
				impossible[map[i][j]] = true;
			}
		}
	}

	int impossibleCnt = 0;
	int currNum = 0;
	for (int i = 1; i < 10; i++)
	{
		if (impossible[i])
			impossibleCnt++;
		else
			currNum = i;
	}


	if (impossibleCnt == 9)
	{
		//cout << "false" << endl;
		return;
	}

	else
	{
		int nextX = -1;
		int nextY = -1;
		bool check = false;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (i == x && j == y) continue;
				if (map[i][j] == 0) {
					nextX = i;
					nextY = j;
					check = true;
					break;
				}
			}
			if (check) {
				break;
			}
		}

		for (int i = 1; i < 10; i++) {
			if (!impossible[i]) {
				map[x][y] = i;
				zeroCnt--;

				if (zeroCnt == 0) return;
				if (check) {
					solve(nextX, nextY);
				}

				if (zeroCnt == 0) return;
				map[x][y] = 0;
				zeroCnt++;
			}
		}
	}
}

int main()
{
	input();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0)
				solve(i, j);
		}
	}

	output();
}
