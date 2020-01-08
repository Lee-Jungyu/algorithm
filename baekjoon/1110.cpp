#include <iostream>
using namespace std;

int main() {
	int value;
	int temp1, temp2, temp;
	cin >> value;
	temp = value;
	int cnt = 0;
	do {
		temp1 = temp / 10;
		temp2 = temp % 10;
		if (temp1 + temp2 < 10)
			temp = temp2 * 10 + temp1 + temp2;
		
		else
			temp = (temp1 + temp2)%10 + temp2 * 10;

		cnt++;
	} while (temp != value);

	cout << cnt << endl;
}
