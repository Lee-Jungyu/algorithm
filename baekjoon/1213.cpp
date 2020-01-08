#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char pal[51];
	char result[51];
	int alpha[26] = { 0, };
	int rest[26] = { 0, };
	cin.getline(pal, 51);
	for (int i = 0; i < strlen(pal); i++) {
		alpha[pal[i] - 65]++;
		rest[pal[i] - 65]++;
	}

	bool check;
	if (strlen(pal) % 2 == 1) check = false;
	else check = true;

	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 == 1) {
			if (!check) {
				check = true;
				result[strlen(pal) / 2] = i + 65;
				rest[i]--;
			}
			else {
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
		}
	}

	for (int i = 0; i < strlen(pal) / 2; ) {
		for (int j = 0; j < 26; j++) {
			if (rest[j] > alpha[j] / 2) {
				result[i++] = j + 65;
				rest[j]--;
				break;
			}
		}
	}
	for (int i = strlen(pal) - 1; i >= (strlen(pal) + 1) / 2; i--) {
		result[i] = result[strlen(pal) - 1 - i];
	}
	for (int i = 0; i < strlen(pal); i++) cout << result[i];
	cout << endl;
}
