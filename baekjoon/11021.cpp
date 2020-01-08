#include <iostream>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", t + 1, a + b);
	}
}
