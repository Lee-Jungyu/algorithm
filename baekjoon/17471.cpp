#include <iostream>
using namespace std;

int N;
int population[11];
bool link[11][11] = { {false,}, };
bool area[11] = { false, };
int _min = 999999999;
bool checked[2000];

void input()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &population[i]);

	int n, m;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &m);
			link[i][m] = true;
		}
	}
}

bool linkCheck()
{
	bool visited[11] = { false, };

	int _stack[100];
	int _top = -1;

	int start1 = 0;
	int start2 = 0;

	for (int i = N; i >= 1; i--) {
		if (area[i] == true) start1 = i;
		else start2 = i;
	}

	// district 1
	_stack[++_top] = start1;
	while (_top != -1) {
		int v = _stack[_top--];
		visited[v] = true;

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && link[v][i] && area[i] == true) {
				_stack[++_top] = i;
			}
		}
	}

	// distrcit 2
	_stack[++_top] = start2;
	while (_top != -1) {
		int v = _stack[_top--];
		visited[v] = true;

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && link[v][i] && area[i] == false) {
				_stack[++_top] = i;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == false) return false;
	}
	return true;
}

int bin2dec()
{
	int bin[10] = { 1,2,4,8,16,32,64,128,256,512 };
	int dec = 0;
	for (int i = 1; i <= N; i++)
	{
		dec += (area[i] * bin[i - 1]);
	}

	return dec;
}

void dfs(int n, int cnt)
{
	area[n] = true;
	checked[bin2dec()] = true;
	bool checkLink = linkCheck();

	if (checkLink) {
		int a1 = 0, a2 = 0;

		for (int i = 1; i <= N; i++)
		{
			if (area[i] == true) a1 += population[i];
			else a2 += population[i];
		}

		if (a1 > a2) {
			if (_min > a1 - a2) _min = a1 - a2;
		}
		else {
			if (_min > a2 - a1) _min = a2 - a1;
		}
	}

	if (cnt == N - 1) {
		area[n] = false;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (area[i] == false && i != n) {
			bool b = false;
			area[i] = true;
			if (!checked[bin2dec()]) b = true;
			area[i] = false;

			if(b)
				dfs(i, cnt + 1);
		}
	}

	area[n] = false;
}

void solve()
{
	for (int i = 1; i <= N; i++)
	{
		dfs(i, 1);
	}
}

void output()
{
	if (_min != 999999999)
		printf("%d\n", _min);
	else
		printf("-1\n");
}

int main()
{
	input();
	solve();
	output();
}

