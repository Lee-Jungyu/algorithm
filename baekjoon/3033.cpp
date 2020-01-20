#include <iostream>
#include <algorithm>
using namespace std;

int L;
int t;
char str[200001];
int suffixArray[200001];
int g[200001];
int tg[200001];
int _rank[200001];
int lcp[200001];
int longest = 0;

void input()
{
	scanf("%d", &L);
	scanf("%s", str);
}

bool cmp(int x, int y)
{
	if (g[x] == g[y])
		return g[x + t] < g[y + t];
	
	return g[x] < g[y];
}

void makeSFA()
{
	//make suffix array
	for (int i = 0; i < L; i++)
	{
		suffixArray[i] = i;
		g[i] = str[i] - 'a';
	}

	t = 1;

	while (t <= L) {
		g[L] = -1;
		sort(suffixArray, suffixArray + L, cmp);
		tg[suffixArray[0]] = 0;

		for (int i = 1; i < L; i++)
		{
			if (cmp(suffixArray[i - 1], suffixArray[i]))
				tg[suffixArray[i]] = tg[suffixArray[i - 1]] + 1;

			else
				tg[suffixArray[i]] = tg[suffixArray[i - 1]];
		}

		for (int i = 0; i < L; i++)
			g[i] = tg[i];

		t *= 2;
	}
}

void LCP()
{
	//longest common prefix
	for (int i = 0; i < L; i++)
		_rank[suffixArray[i]] = i;

	int len = 0;

	for (int i = 0; i < L; i++)
	{
		int k = _rank[i];
		if (k) {
			int j = suffixArray[k - 1];

			while (str[j + len] == str[i + len])
				len++;

			lcp[k] = len;

			if (longest < len) longest = len;

			if (len)
				len--;
		}
	}
}

void output()
{
	printf("%d\n", longest);
}

int main()
{
	input();

	if (L == 1) {
		printf("0\n");
		return 0;
	}

	makeSFA();
	LCP();
	output();
}
