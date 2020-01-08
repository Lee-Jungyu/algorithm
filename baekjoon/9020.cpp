#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		int cnt = 0;
		cin >> n;
		if (n == 4) {
			cout << 2 << " " << 2 << endl;
			continue;
		}
		bool s[100000];
		int ss[100000];
		for (int i = 0; i < n; i++) {
			s[i] = true;
		}
		s[0] = s[1] = false;
		for (int i = 2; i <= n; i++) {
			if (s[i]) {
				ss[cnt++] = i;
				for (int j = i * i; j <= n; j += i) {
					s[j] = false;
				}
			}
		}
		int min = n;
		int a, b;
		for (int i = 2; i < n/2 + 1; i++) {
			if (s[i] && s[n - i]) {
				if (n - 2 * i < min)
					a = i; b = n - i;
			}
		}
		cout << a << " " << b << endl;
	}
}
