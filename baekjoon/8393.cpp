#include <iostream>
using namespace std;
int main() {
	int n, t = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		t += i;
	}
	cout << t << endl;
	return 0;
}
