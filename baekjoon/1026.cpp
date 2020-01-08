#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define N 50

int A[N];
int B[N];

int compare(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int main()
{
	int cnt;
	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < cnt; i++) {
		scanf("%d", &B[i]);
	}

	sort(A, A + cnt, greater<int>());
	sort(B, B + cnt);

	int sum = 0;
	for (int i = 0; i < cnt; i++)
	{
		sum += A[i] * B[i];
	}

	printf("%d", sum);
	
	return 0;
}
