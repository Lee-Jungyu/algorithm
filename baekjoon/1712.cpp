#include <iostream>
using namespace std;

int main()
{
	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);

	if (B == C || B > C) {
		printf("-1\n");
	}
	else {
		printf("%d\n", A / (C - B) + 1);
	}
}
