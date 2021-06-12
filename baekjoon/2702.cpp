#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int n1, n2;
		cin >> n1 >> n2;

		int GCD = 1, LCM = 1;

		bool check = true;
		while (check) {
			int small = n1 < n2 ? n1 : n2;
			if (small == 1) break;

			for (int i = 2; i <= small; i++) {
				if (n1 % i == 0 && n2 % i == 0) {
					check = true;
					
					GCD *= i;
					n1 /= i;
					n2 /= i;

					break;
				}

				if (i == small) check = false;
			}
		}

		LCM = n1 * n2 * GCD;
		cout << LCM << " " << GCD << endl;
	}

	return 0;
}
