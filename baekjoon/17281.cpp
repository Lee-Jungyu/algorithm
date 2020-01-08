#include <iostream>
using namespace std;

int N;
int map[50][9];
int visited[9];
int order[9];
int base[3];
int maxScore = 0;


void input()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

void start()
{
	int inning = 0;
	int currOrder = order[0];
	int outCnt = 0;
	int score = 0;

	for (int i = 0; ; i++)
	{
		if (inning == N) {
			if (maxScore < score) maxScore = score;
			return;
		}
		int result = map[inning][order[i % 9]];

		if (result == 0) {
			outCnt++;

			if (outCnt == 3) {
				for (int j = 0; j < 3; j++) {
					base[j] = 0;
				}

				inning++;
				outCnt = 0;
			}
		}

		else if (result == 1) {
			if (base[2]) {
				score++;
				base[2] = 0;
			}
			if (base[1]) {
				base[2] = 1;
				base[1] = 0;
			}
			if (base[0]) {
				base[1] = 1;
				base[0] = 0;
			}

			base[0]++;

		}

		else if (result == 2) {
			if (base[2]) {
				score++;
				base[2] = 0;
			}
			if (base[1]) {
				score++;
				base[1] = 0;
			}
			if (base[0]) {
				base[2] = 1;
				base[0] = 0;
			}

			base[1]++;
		}

		else if (result == 3) {
			if (base[2]) {
				score++;
				base[2] = 0;
			}
			if (base[1]) {
				score++;
				base[1] = 0;
			}
			if (base[0]) {
				score++;
				base[0] = 0;
			}

			base[2]++;
		}

		else {
			int sum = 1;
			for (int j = 0; j < 3; j++)
			{
				if (base[j]) {
					sum++;
					base[j] = 0;
				}
			}
			score += sum;
		}
	}

}

void makeOrder(int o, int n) {
	
	visited[n] = 1;
	order[o] = n;

	o++;
	if (o == 3) o++;
	if (o == 9) {
		start();
		visited[n] = 0;
		return;
	}

	for (int i = 1; i < 9; i++) {
		if (visited[i]) continue;
		makeOrder(o, i);
	}

	visited[n] = 0;
}

void solve()
{
	order[3] = 0;
	visited[0] = true;

	for (int i = 1; i < 9; i++) {
		makeOrder(0, i);
	}
}

void output()
{
	printf("%d\n", maxScore);
}

int main()
{
	input();
	solve();
	output();
}
