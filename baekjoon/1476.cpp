#include <iostream>
using namespace std;

int E, S, M;
int year[16][29][20];
int main()
{
	scanf("%d %d %d", &E, &S, &M);
	int i = 1;
	int j = 1;
	int k = 1;
	int cnt = 1;

	while (!(i == E && j == S && k == M))
	{
		i = i % 15 + 1;
		j = j % 28 + 1;
		k = k % 19 + 1;
		cnt++;

	}

	printf("%d\n", cnt);
}
