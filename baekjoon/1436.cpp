#include <iostream>
using namespace std;

int num[10000];
int main()
{
	int N;
	int cnt = 0;
	int a, b, c, d, e, f, g, h;

	scanf("%d", &N);
	
	for (int i = 666; i <= 10000666; i++)
	{
		a = i / 10000000;
		b = i % 10000000 / 1000000;
		c = i % 1000000 / 100000;
		d = i % 100000 / 10000;
		e = i % 10000 / 1000;
		f = i % 1000 / 100;
		g = i % 100 / 10;
		h = i % 10;

		if (a == 6 && b == 6 && c == 6) {
			cnt++;
		}
		else if (b == 6 && c == 6 && d == 6) {
			cnt++;
		}
		else if (c == 6 && d == 6 && e == 6) {
			cnt++;
		}
		else if (d == 6 && e == 6 && f == 6) {
			cnt++;
		}
		else if (e == 6 && f == 6 && g == 6) {
			cnt++;
		}
		else if (f == 6 && g == 6 && h == 6) {
			cnt++;
		}

		if (cnt == N)
		{
			printf("%d\n", i);
			break;
		}
	}
}
