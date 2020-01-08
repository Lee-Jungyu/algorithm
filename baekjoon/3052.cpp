#include <iostream>
using namespace std;

int modul42[42];

int main()
{
	int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		int n;
		scanf("%d", &n);

		if (modul42[n % 42] == 0) {
			cnt++;
			modul42[n % 42] = 1;
		}
	}

	printf("%d\n", cnt);
}
