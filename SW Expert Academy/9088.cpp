#include <iostream>
using namespace std;

int TC;
int N, K;
int dia[20001] = { 0, };
int dp[20001] = { 0, };

int main()
{
	int a, _min = 10001, _max = -1;
	int _maxCnt = 0;

	scanf("%d", &TC);

	for (int t = 1; t <= TC; t++)
	{
		scanf("%d %d", &N, &K);

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &a);
			
			if (a < _min) _min = a;
			if (a > _max) _max = a;

			dia[a]++;
		}

		for (int i = _min; i <= _max + K; i++)
		{
			dp[i] = dp[i - 1] + dia[i];
		}

		for (int i = _min; i <= _max; i++)
		{
			int sum = dp[i + K] - dp[i - 1];
			if (sum > _maxCnt) _maxCnt = sum;
		}

		printf("#%d %d\n", t, _maxCnt);

		_maxCnt = 0;

		for (int i = _min; i <= _max + K; i++)
		{
			dia[i] = 0;
		}

	}

	return 0;
}
