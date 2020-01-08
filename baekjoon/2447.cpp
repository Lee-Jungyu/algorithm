#include <iostream>
using namespace std;

int N;
char map[3000][3000];

void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = ' ';
}

void print(int n, int x, int y)
{
	if (n == 1) {
		map[x][y] = '*';
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(i == 1 && j == 1)
				continue;
			print(n / 3, i+3*x, j+3*y);
		}
	}

}

void output()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			printf("%c", map[i][j]);
		}
		cout << endl;
	}
}

int main()
{
	scanf("%d", &N);
	init();
	print(N, 0, 0);
	output();
}
