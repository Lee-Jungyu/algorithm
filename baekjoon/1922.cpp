#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int M;
int result;

class Edge {
public:
	int v1;
	int v2;
	int value;

	Edge() {}
	bool operator < (Edge &other) {
		return value < other.value;
	}
};

Edge e[100001];
int parent[1001];

void input()
{
	scanf("%d", &N);
	scanf("%d", &M);
	int a, b, v;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &a, &b, &v);
		e[i].v1 = a;
		parent[a] = a;
		e[i].v2 = b;
		parent[b] = b;
		e[i].value = v;
	}
}

void solve()
{
	if (N == 1) {
		result = 0; 
		return;
	}
	if (M == 1) {
		result = e[0].value; 
		return;
	}
	sort(e, e + M);

	int sum = 0;
	for (int i = 0; i < M; i++)
	{
		if (parent[e[i].v1] == parent[e[i].v2]) {
			continue;
		}
		else if (parent[e[i].v1] < parent[e[i].v2]) {
			sum += e[i].value;
			int p = parent[e[i].v2];
			for (int j = 1; j <= N; j++) {
				if(p == parent[j])
					parent[j] = parent[e[i].v1];
			}
		}
		else {
			sum += e[i].value;
			int p = parent[e[i].v1];
			for (int j = 1; j <= N; j++) {
				if (p == parent[j])
					parent[j] = parent[e[i].v2];
			}
		}

	}

	result = sum;

	return;
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
