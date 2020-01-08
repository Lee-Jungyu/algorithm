#include <iostream>
using namespace std;

int output[10];
bool visit[10];

void permutation(int num, int idx, int n) {
	output[idx] = num;

	if (idx + 1 == n) {
		for (int i = 0; i < n; i++) printf("%d ",output[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		permutation(i + 1, idx + 1, n);
		visit[i] = 0;
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		visit[i] = 1;
		permutation(i + 1, 0, n);
		visit[i] = 0;
	}
}
