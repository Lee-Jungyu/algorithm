#include <iostream>
using namespace std;

int num[101];
int main()
{
	int N;
	int M;
	int max = 0;
	int sum = 0;

	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				sum = num[i] + num[j] + num[k];
				if (sum > M) {
					continue;
				}
				else if (sum > max) {
					max = sum;
				}
				else {
					continue;
				}
			}
		}
	}

	printf("%d\n", max);

	return 0;
}
