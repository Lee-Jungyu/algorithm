#include <iostream>
using namespace std;

int main() 
{
	bool b[1000001] = { true,true };
	int m, n;
	cin >> m >> n;
	for (int i = 2; i * i <= n; i++) {
		if (!b[i]) {
			for (int j = i + i; j <= n; j += i) {
				b[j] = true;
			}
		}
	}
	for (int i = m; i <= n; i++)
		if (!b[i])
			cout << i << "\n";
	return 0;
}
