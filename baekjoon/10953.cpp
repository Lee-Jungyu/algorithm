#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;

		int sum = (str[0] - '0') + (str[2] - '0');
		cout << sum << endl;
	}
}
