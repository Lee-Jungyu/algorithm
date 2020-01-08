#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int five = 0, three = 0;

	while (n >= 5) {
			n -= 5;
			five++;
	}
	while (n != 0) {
		if (n % 3 == 0) {
			three++;
			n -= 3;
		}
		else {
			five--;
			n += 5;
		}
		if (five < 0)
		{
			five = -1; three = 0;
			break;
		}
	}
	cout << five + three;
}
