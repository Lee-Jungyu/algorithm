#include <iostream>
using namespace std;
int main() {
	int n, max = 0;
	double p[1000], t = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		if (max < p[i]) max = p[i];
	}
	for (int i = 0; i < n; i++) {
		p[i] = p[i] / max * 100.0;
		t += p[i];
	}
	double ave = t / n;
	printf("%0.2f\n", ave);
	return 0;
}
