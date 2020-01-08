#include <iostream>
using namespace std;

int num[7] = { 0, };
int cnt[10] = { 0, };
int main()
{
	int N, a, idx = 0, count = 0;
	scanf("%d", &N);

	if (N == 0) {
		printf("1\n");
		return 0;
	}

	while (N != 0)
	{
		a = N % 10;
		num[idx++] = a;
		N /= 10;
		count++;
	}
	
	for (int i = 0; i < count; i++)
	{
		int b = num[i];
		cnt[b]++;
	}

	int set69 = 0;
	if ((cnt[6] + cnt[9]) % 2 == 1)
	{
		set69 = (cnt[6] + cnt[9]) / 2 + 1;
	}
	else
	{
		set69 = (cnt[6] + cnt[9]) / 2;
	}
	int set = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i == 6) continue;
		if (set < cnt[i]) set = cnt[i];
	}
	if (set69 > set) printf("%d\n", set69);
	else printf("%d\n", set);

	return 0;
}
