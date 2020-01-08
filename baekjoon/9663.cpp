#include <iostream>
using namespace std;

int N;
int map[15][15] = { 0, };
int result = 0;

// 1 2
// 0 1, 1 2, 2 3, 3 4

void print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void solve(int cnt, int x, int y)
{
	map[x][y] = 1;

	if (cnt == N - 1) {
		//print();
		result++;
		map[x][y] = 0;
		return;
	}

	bool lat = true;
	bool lng = true;
	bool diagonal = true;

	int i = x + 1;
	for (int j = 0; j < N; j++) {

		if (map[i][j] == 1) continue;

		lat = true;
		lng = true;
		diagonal = true;

		for (int k = 0; k < N; k++) {
			if (map[k][j] != 0) {
				lng = false;
				break;
			}
			if (map[i][k] != 0) {
				lat = false;
				break;
			}

			if (k - i + j >= 0 && k - i + j < N) {
				if (map[k][k - i + j] != 0) {
					diagonal = false;
					break;
				}
			}
			if (-k + i + j >= 0 && -k + i + j < N) {
				if (map[k][-k + i + j] != 0) {
					diagonal = false;
					break;
				}
			}
		}

		if (lng && lat && diagonal) {
			solve(cnt + 1, i, j);
		}
	}

	map[x][y] = 0;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		solve(0, 0, i);
	}
	printf("%d\n", result);
}
