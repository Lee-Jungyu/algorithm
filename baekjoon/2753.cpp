#include <iostream>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	if (N % 400 == 0) {
		printf("1\n");
	}
	else if (N % 100 == 0) {
		printf("0\n");
	}
	else if (N % 4 == 0) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
}
