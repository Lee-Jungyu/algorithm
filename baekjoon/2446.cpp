#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < 2 * N - i - 1; j++) {
			if (j < i) cout << " ";
			else cout << "*";
		}
		cout << endl;
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0;  j < 2 * N - i - 1; j++) {
			if (j < i) cout << " ";
			else cout << "*";
		}
		if (i != 0)
			cout << endl;
	}
}
