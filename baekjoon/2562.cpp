#include <iostream>
using namespace std;

int main()
{
	int max = 0;
	int flag = 0;
	for (int i = 1; i < 10; i++)
	{
		int n;
		scanf("%d", &n);

		if (max < n) {
			max = n;
			flag = i;
		}
	}

	printf("%d\n%d\n", max, flag);
}
