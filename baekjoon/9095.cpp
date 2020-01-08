#include <iostream>
using namespace std;

int main()
{
	int num[11];
	int n, tc;
	cin >> tc;
	num[1] = 1;
	num[2] = 2;
	num[3] = 4;

	while (tc--) {
		cin >> n;
		for (int i = 4; i <= n; i++) {
			num[i] = num[i - 3] + num[i - 2] + num[i - 1];
		}

		cout << num[n] << endl;
	}
}
