#include <iostream>
using namespace std;

int X;
int cal();

int main() {
	cin >> X;
	cout << cal() << endl;
	return 0;
}

int cal() {
	int cnt = 1;
	int shortest = 64;
	int total = 64;
	while (total != X) {
		shortest /= 2;
		cnt++;
		if (X <= total - shortest) {
			total -= shortest;
			cnt--;
		}
	
	}
	return cnt;
}
