#include <iostream>
using namespace std;

int main() {
	char c[1000001];
	bool check = true;
	int cnt = 0;
	cin.getline(c,1000000);
	for (int i = 0; c[i] != '\0'; i++) {
		if (c[i] == ' ') {
			check = true;
			continue;
		}
		else {
			if (check) {
				cnt++; check = false;
			}
		}
	}
	cout << cnt << endl;
}
