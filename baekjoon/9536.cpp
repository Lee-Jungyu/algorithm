#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string word[101];
		string animal[101];
		string goes[101];
		string cry[101];

		int i = 0;
		int j = 0;
		while (1)
		{
			cin >> word[i++];
			if (getchar() == '\n') break;
		}

		while (1)
		{
			string a;
			string g;
			string c;
			cin >> a >> g >> c;
			if (g != "goes") break;
			animal[j] = a;
			goes[j] = g;
			cry[j] = c;
			j++;
		}
		string fox, say;
		cin >> fox >> say;
		for (int a = 0; a < i; a++)
		{
			for (int b = 0; b < j; b++) {
				if (cry[b] == word[a])
					b = j;
				if (b == j - 1)
					cout << word[a] << " ";
			}
		}
		cout << endl;
	}
}
