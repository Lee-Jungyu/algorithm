#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int a, b, T;
	cin >> T;
	for(int i = 0; i < T; i++) {
		cin >> a >> b;
		cout << a + b << '\n';
	}
	return 0;
}
