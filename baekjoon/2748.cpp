#include <iostream>
using namespace std;

int n;
int64_t fibo[91];

int main()
{
	scanf("%d", &n);
	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i < n + 1; i++) {
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}
	
	printf("%llu\n", fibo[n]);
}
