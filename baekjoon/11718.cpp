#include <iostream>
#include <string>
using namespace std;
int main() {
	string word;
	while (1)
	{
		getline(cin, word);
		if (word == "")
			break;
		cout << word << '\n';
	}
}
