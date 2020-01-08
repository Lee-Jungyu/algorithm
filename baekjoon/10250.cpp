#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int w, h, n;
		cin >> h >> w >> n;
		int f, r;
		f = n % h;
		if (f == 0) f = h;
		r = ((n - 1) / h) + 1;
		cout << f * 100 + r << endl;
	}
}
