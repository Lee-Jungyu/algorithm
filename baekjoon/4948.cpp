#include <iostream>
using namespace std;

int main()
{
	int n = 1;
	while (true) {
		bool b[250000] = { true,true };
		int cnt = 0;
		cin >> n;
		if (n == 0)
			break;
		for (int i = 2; i * i <= 2 * n; i++) {
			if (!b[i]) {
				for (int j = i + i; j <= 2 * n; j += i) {
					b[j] = true;
				}
			}
		}
		for (int i = n + 1; i <= 2 * n; i++)
			if (!b[i])
				cnt++;
		cout << cnt << endl;
	}
}
