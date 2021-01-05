#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b, c;
	cin >> a >> b;

	int a_idx = a.length() - 1;
	int b_idx = b.length() - 1;

	bool up = false;
	while (true) {

		if (a_idx == -1 || b_idx == -1) break;

		int tmp = a[a_idx] - '0' + b[b_idx] - '0';
		
		if (up) tmp += 1;
		up = false;

		if (tmp > 9) {
			up = true;
			tmp -= 10;
		}

		c = (char)(tmp + '0') + c;

		a_idx--;
		b_idx--;
	}

	for (int i = a_idx; i >= 0; i--) {
		if (up) {
			int tmp = (a[i] - '0') + 1;
			if (tmp >= 10) {
				tmp -= 10;
				up = true;
			}
			else {
				up = false;
			}
			c = (char)(tmp + '0') + c;
		}
		else {
			c = a[i] + c;
		}
	}

	for (int i = b_idx; i >= 0; i--) {
		if (up) {
			int tmp = (b[i] - '0') + 1;
			if (tmp >= 10) {
				tmp -= 10;
				up = true;
			}
			else {
				up = false;
			}
			c = (char)(tmp + '0') + c;
		}
		else {
			c = b[i] + c;
		}
	}

	if (up) c = '1' + c;

	cout << c << endl;

	return 0;
}
