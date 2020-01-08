#include <iostream>
using namespace std;
int main() {
	int m, d, t = 0;
	int month[11] = { 31,28,31,30,31,30,31,31,30,31,30 };
	cin >> m >> d;
	for (int i = 0; i < m - 1; i++) {
		t += month[i];
	}
	t += d;
	t -= 1;
	switch (t % 7) {
	case 0:
		cout << "MON" << endl;
		break;
	case 1:
		cout << "TUE" << endl;
		break;
	case 2:
		cout << "WED" << endl;
		break;
	case 3:
		cout << "THU" << endl;
		break;
	case 4:
		cout << "FRI" << endl;
		break;
	case 5:
		cout << "SAT" << endl;
		break;
	case 6:
		cout << "SUN" << endl;
		break;
	default:
		break;
	}
	return 0;
}
