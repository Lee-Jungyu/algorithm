#include <iostream>
using namespace std;
int main() {
	int n;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int no;
		bool check = false;
		cin >> no;
		if (no == 1) continue;
		for (int i = 2; i < no; i++) {
			if (no % i == 0) {
				check = true;
				break;
			}
		}
		if (!check)
			cnt++;
	}

	cout << cnt;
}
