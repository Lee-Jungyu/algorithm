#include <iostream>
using namespace std;
int arr[7];

int main()
{
	int N;
	scanf("%d", &N);
	int num = N;

	int flag;

	for (int i = 0; i < N; i++) {

		flag = 0;
		num = i;

		while (num) {
			arr[flag++] = num % 10;
			num = num / 10;
		}

		int sum = i;
		for (int j = 0; j < flag; j++) {
			sum += arr[j];
		}

		if (sum == N) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", 0);
}
