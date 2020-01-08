#include <iostream>
using namespace std;

int arr[15][15];

int res(int a, int b)
{
	int sum = 0;
	for (int i = 0; i <= b; i++)
	{
		sum += arr[a - 1][i];
	}
	return sum;
}

int main()
{
	int T, k, n;

	for (int i = 0; i < 15; i++)
	{
		arr[i][0] = 0;
		arr[i][1] = 1;
		arr[0][i] = i;
	}

	for (int i = 1; i < 15; i++)
		for (int j = 1; j < 15; j++)
			arr[i][j] = res(i, j);

	scanf("%d", &T);
	
	while (T--)
	{
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d\n", arr[k][n]);
	}
	return 0;
}
