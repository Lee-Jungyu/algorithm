#include <iostream>
#include <algorithm>
#include <string>
#define FAST_IO cin.tie(0); ios_base::sync_with_stdio(false);

using namespace std;

int t;
int n;
string result = "";

struct Trie {
	int cnt;
	char data;
	Trie* subTrie[11];

	Trie() {
		cnt = 0;
		data = ' ';
		for (int i = 0; i < 11; i++) {
			subTrie[i] = NULL;
		}
	}
	
};

Trie *rootTrie;

void insertNode(string str)
{
	Trie* triePtr = rootTrie;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '.') {
			triePtr->cnt++;
			triePtr->subTrie[10] = new Trie();
			triePtr = triePtr->subTrie[10];
			triePtr->data = '.';
		}
		else {
			if (triePtr->subTrie[str[i] - '0'] == NULL) {
				triePtr->cnt++;
				triePtr->subTrie[str[i] - '0'] = new Trie();
				triePtr = triePtr->subTrie[str[i] - '0'];
				triePtr->data = str[i];
			}
			else {
				triePtr = triePtr->subTrie[str[i] - '0'];
			}
		}
	}
}

void checkNode(Trie* triePtr)
{
	if (triePtr->cnt > 1) {
		if (triePtr->subTrie[10] != NULL)
		{
			result = "NO";
			return;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (result == "NO") return;
		if (triePtr->subTrie[i] != NULL) checkNode(triePtr->subTrie[i]);
	}

}

void deleteNode(Trie* triePtr)
{
	for (int i = 0; i < 10; i++) {
		if (triePtr->subTrie[i] != NULL)
		{
			deleteNode(triePtr->subTrie[i]);
			triePtr->subTrie[i] = NULL;
			triePtr->cnt--;
		}
	}

	delete triePtr;
}

void input()
{
	string number;
	cin >> number;
	number += '.';
	insertNode(number);
}

void solve()
{
	checkNode(rootTrie);
	if (result == "") result = "YES";
	cout << result << '\n';
}

int main()
{
	FAST_IO;

	cin >> t;
	while (t--) {
		rootTrie = new Trie();
		result = "";

		cin >> n;
		for (int i = 0; i < n; i++) {
			input();
		}
		solve();
		deleteNode(rootTrie);
	}
}
