#include <iostream>
using namespace std;

int main()
{
	int H, M;
	scanf("%d %d", &H, &M);

	if (M < 45) {
		M = 60 + M - 45;
		H -= 1;
	}
	else {
		M -= 45;
	}

	if (H < 0) {
		H = 24 + H;
	}

	printf("%d %d\n", H, M);
}
