#include <iostream>
using namespace std;

int N;
int cnt;
void hanoi(int n, int from, int to, int other)
{
	if (n == 1) {
		printf("%d %d\n", from, to);
	}

	else {
		hanoi(n - 1, from, other, to);
		hanoi(1, from, to, other);
		hanoi(n - 1, other, to, from);
	}
}

int main()
{
	scanf("%d", &N);
	int sum = 1;
	for (int i = 0; i < N; i++) {
		sum *= 2;
	}
	sum -= 1;
	printf("%d\n", sum);
	
	hanoi(N, 1, 3, 2);

}
