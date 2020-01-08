#include <iostream>
using namespace std;

int n;
int fibo[1000001];

int main()
{
	scanf("%d", &n);
	fibo[1] = 1;
	fibo[2] = 2;

	for (int i = 3; i < n + 1; i++) {
		fibo[i] = fibo[i - 2] % 15746 + fibo[i - 1] % 15746;
	}
	
	printf("%d\n", fibo[n] % 15746);
}
