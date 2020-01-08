#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string str;
	cin >> str;
	int middle;
	bool check = true;
	if (str.length() % 2 == 0) {
		middle = str.length() / 2 - 1;
		for (int i = middle, j = middle + 1; i >= 0 && j < str.length(); i--, j++) {
			if (str[i] != str[j]) {
				cout << 0 << endl;
				check = false;
				break;
			}
		}
		if (check) cout << 1 << endl;
	}
	else {
		middle = str.length() / 2;
		for (int i = middle - 1, j = middle + 1; i >= 0 && j < str.length(); i--, j++) {
			if (str[i] != str[j]) {
				cout << 0 << endl;
				check = false;
				break;
			}
		}
		if (check) cout << 1 << endl;
	}
}
