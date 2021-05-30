#include <iostream>
using namespace std;

int arr[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	bool check = false;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == sum - 100) {
				arr[i] = 0;
				arr[j] = 0;
				check = true;
				break;
			}
		}
		if (check) break;
	}

	for (int i = 0; i < 9; i++) {
		int k = i;
		for (int j = i + 1; j < 10; j++) {
			if (arr[k] > arr[j]) {
				int tmp = arr[k];
				arr[k] = arr[j];
				arr[j] = tmp;
			}
		}
	}


	for (int i = 0; i < 10; i++) {
		if(arr[i]) cout << arr[i] << endl;
	}

	return 0;
}
