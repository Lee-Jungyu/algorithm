#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(const string &a, const string &b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else
		return a < b;
}

int main() {
	int n;
	string str[20000];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> str[i];

	sort(str, str + n, cmp);

	string temp = "";
	for (int i = 0; i < n; i++) {
		if (temp != str[i])
			cout << str[i] << endl;
		temp = str[i];
	}

	return 0;
}
