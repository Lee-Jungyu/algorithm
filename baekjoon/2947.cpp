#include <iostream>
using namespace std;

int arr[5];
int main()
{
	for (int i = 0; i < 5; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) {
		if (arr[i] > arr[i + 1]) {
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << endl;
		}
		if (i == 3) {
			for (int j = 0; j < 4; j++) {
				if (arr[j] > arr[j + 1]) {
					i = -1;
					j = 4;
					break;
				}
			}
		}
	}
}
