#include <stdio.h>
#include <vector>
using namespace std;

int N;
int M;
vector<int> v[50001];
bool visited[50001] = { false, };
int tree[50001][2]; //0: parent, 1: layer

void makeTree(int num, int p, int l)
{
	visited[num] = true;
	tree[num][0] = p;
	tree[num][1] = l;

	for (int i = 0; i < v[num].size(); i++)
	{
		if(!visited[v[num][i]])
			makeTree(v[num][i], num, l + 1);
	}
}

int LCA(int a, int b)
{
	int pa = a;
	int pb = b;

	while (tree[pa][1] > tree[pb][1]) {
		pa = tree[pa][0];
	}
	while (tree[pa][1] < tree[pb][1]) {
		pb = tree[pb][0];
	}

	while (pa != pb) {
		pa = tree[pa][0];
		pb = tree[pb][0];
	}

	return pa;
}

int main()
{
	scanf("%d", &N);
	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	makeTree(1, 1, 0);

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));
	}
}
