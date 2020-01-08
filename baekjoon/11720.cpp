#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, t = 0;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		t += s[i] - 48;
	}
	cout << t << endl;
	return 0;
}
