#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	string str[100];
	for (int i = 0; i < t; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < t; i++) {
		for (int j = i; j < t; j++) {
			if (str[i].length() == str[j].length()) {
				bool check = true;
				for (int k = 0; k < str[i].length(); k++) {
					if (str[i][k] != str[j][str[i].length() - k - 1])
					{
						check = false;
						k = str[i].length();
					}
				}
				if (check) {
					cout << str[i].length() << " " << str[i][str[i].length() / 2] << endl;
					return 0;
				}
			}
		}
	}
}
