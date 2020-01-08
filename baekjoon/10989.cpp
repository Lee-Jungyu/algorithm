#include <stdio.h>
using namespace std;

int main() {
	int arr[10001] = { 0, };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		arr[num]++;
	}
	for (int i = 0; i < 10001; i++) {
		while (arr[i] != 0) {
			printf("%d\n", i);
			arr[i]--;
		}
	}

	return 0;
}
