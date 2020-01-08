#include <iostream>
using namespace std;

int main() {
	int n, m;
	int idx[101];
	int print[101];
	int order[101];
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			idx[i] = i;
			cin >> print[i];
			order[i] = print[i];
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (order[i] < order[j]) {
					int temp = order[i];
					order[i] = order[j];
					order[j] = temp;
				}
			}
		}
		int order_check = 0;
		for (int i = 0; i < n;) {
			if (print[i] < order[order_check]) {
				int temp = print[i];
				int i_temp = idx[i];
				int j = 0;
				for (j = i; j < n - 1; j++) {
					print[j] = print[j + 1];
					idx[j] = idx[j + 1];
				}
				print[j] = temp;
				idx[j] = i_temp;
			}
			if (print[i] == order[order_check]) {
				order_check++;
				i++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (idx[i] == m)
				cout << i + 1 << endl;
		}
	}
	return 0;
}
