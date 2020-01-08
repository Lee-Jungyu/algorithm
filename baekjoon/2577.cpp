#include <iostream>
using namespace std;

int main()
{
	int mul = 1, a;
	int num[10] = { 0, };
	for (int i = 0; i < 3; i++) {
		cin >> a;
		mul *= a;
	}

	while (mul != 0) {
		num[mul % 10]++;
		mul /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << num[i] << endl;
	}
}
