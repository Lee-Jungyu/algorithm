#include <iostream>
using namespace std;

int main() {
	char c[7];
	int i = 0;
	int idx = 0;
	cin.getline(c, 7);
	do {
		if (c[idx] >= 48 && c[idx] <= 57) {
			i *= 16;
			i += c[idx] - 48;
		}
		else {
			i *= 16;
			i += c[idx] - 55;
		}
		idx++;
	} while (c[idx] != '\0');
	cout << i << endl;
}
