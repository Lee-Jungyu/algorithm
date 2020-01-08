#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	string str;
	string temp;
	for (int i = 0; i < t; i++) {
		cin >> str;
		if (i == 0) temp = str;
		else {
			for (int i = 0; i < str.length(); i++) {
				if (temp[i] != str[i]) temp[i] = '?';
			}
		}
	}
	cout << temp << endl;
}
