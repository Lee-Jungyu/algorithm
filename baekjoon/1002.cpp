#include <iostream>
#include <math.h>
using namespace std;

int t;
int x_1, x_2, y_1, y_2, r_1, r_2;

int cal();
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
		cout << cal() << endl;
	}

	return 0;
}

int cal() {
	double dist = sqrt((x_2 - x_1)*(x_2 - x_1)+(y_2 - y_1)*(y_2 - y_1));
	if (abs(r_1 - r_2) > dist) return 0;
	else if (abs(r_1 - r_2) == dist) {
		if (r_1 == r_2) return -1;
		return 1;
	}
	else if (dist > r_1 + r_2) return 0;
	else if (dist == r_1 + r_2) return 1;
	else if (dist < r_1 + r_2) return 2;
}
