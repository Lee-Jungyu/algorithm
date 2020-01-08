#include <iostream>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int min = 9999999;
	int max = -9999999;
	
	for (int i = 0; i < N; i++)
	{
		int n;
		scanf("%d", &n);
		if (min > n) min = n;
		if (max < n) max = n;
	}

	printf("%d %d\n", min, max);
}
