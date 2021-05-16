#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;

	int small = x < y ? x : y;
	int big = x >= y ? x : y;
	int gcd = 1;

	while (true) {
		bool check = false;
		for (int i = 2; i <= small; i++) {
			if (small % i || big % i)
				continue;

			gcd *= i;
			small /= i;
			big /= i;
			check = true;

			break;
		}

		if (!check) break;
	}

	cout << gcd << endl;
	cout << small * big * gcd << endl;
}
