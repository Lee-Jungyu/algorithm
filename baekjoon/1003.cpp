#include <iostream>
using namespace std;

int main()
{
	int z[41], o[41];
	z[0] = 1, z[1] = 0, z[2] = 1, z[3] = 1;
	o[0] = 0, o[1] = 1, o[2] = 1, o[3] = 2;
	for (int i = 4; i < 41; i++) {
		z[i] = z[i - 1] + z[i - 2];
		o[i] = o[i - 1] + o[i - 2];
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << z[n] << " " << o[n] << endl;
	}
}

