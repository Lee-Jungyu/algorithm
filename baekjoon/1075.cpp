#include <iostream>
using namespace std;

int main()
{
	int N, F;
	
	scanf("%d", &N);
	scanf("%d", &F);

	N = N / 100 * 100;

	int i;
	for (i = 0; i < 100; i++)
	{
		if ((N + i) % F == 0)
			break;
	}

	char c[2];
	c[1] = (char)(i % 10) + '0';
	i /= 10;
	c[0] = (char)(i % 10) + '0';

	printf("%c%c", c[0], c[1]);
}
