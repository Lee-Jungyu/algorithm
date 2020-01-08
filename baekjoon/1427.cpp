#include <iostream>
using namespace std;

int arr[10];

int main()
{
	int N;
	int flag = 0;

	cin >> N;

	while (N) {
		arr[flag++] = N % 10;
		N /= 10;
	}

	for (int i = 0; i < flag - 1; i++)
	{
		int k = i;
		for (int j = i; j < flag; j++) {
			if (arr[j] > arr[k]) {
				k = j;
			}
		}

		int tmp = arr[k];
		arr[k] = arr[i];
		arr[i] = tmp;
	}

	for (int i = 0; i < flag; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}
