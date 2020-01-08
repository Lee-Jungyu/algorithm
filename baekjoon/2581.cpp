#include <iostream>
using namespace std;
int main() {
	int m, n, sum = 0, cnt = 0, min = 0;
	bool first = true;
	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		bool check = true;
		if (i == 1) continue;
		for (int j = 2; j < i / 2 + 1; j++)
		{
			if (i%j == 0) {
				check = false;
				break;
			}
		}
		if (check) {
			if (first) {
				min = i;
				first = false;
			}
			sum += i;
			cnt++;
		}
	}
	if (cnt == 0) sum = -1;
	cout << sum << endl;
	if (sum != -1)
		cout << min;
}
