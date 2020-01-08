#include <iostream>
using namespace std;

int main()
{
	int T;
	int x = 0, y = 0;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d %d", &x, &y);
		int dest = y - x;
		
		int tmp = 0;

		long long rangeA = 1;
		long long rangeB = 1;
		long long i;
		for (i = 1; i < dest;) {
			tmp++;
			i = i + 2 * tmp;
			rangeA = rangeB;
			rangeB = i;
		}

		if (i == dest) {
			printf("%d\n", 1 + 2 * tmp);
		}

		else {
			if (dest - rangeA < rangeB - dest) {
				printf("%d\n", 2 * tmp - 1);
			}
			else {
				printf("%d\n", 2 * tmp);
			}
		}
	}
}

