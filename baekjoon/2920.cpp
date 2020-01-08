#include <iostream>
using namespace std;

int mel[8];
int main()
{
	int c = 0;
	for (int i = 0; i < 8; i++) cin >> mel[i];
	for (int i = 0; i < 7; i++) {
		if (mel[i] != mel[i + 1] - 1) {
			c = 1;
			break;
		}
	}
	if (c == 1) {
		for (int i = 0; i < 7; i++) {
			if (mel[i] != mel[i + 1] + 1) {
				c = 2;
				break;
			}
		}
	}
	if (c == 0) cout << "ascending\n";
	else if (c == 1) cout << "descending\n";
	else cout << "mixed\n";
}
