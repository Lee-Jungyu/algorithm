#include <iostream>
#include <string>
using namespace std;

bool white[8][8];
char board[8][8];
int main()
{
	string str;
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		cin >> str;
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				white[i][j] = true;
			}
			board[i][j] = str[j];

			if (board[i][j] == 'F' && white[i][j]) cnt++;
		}
	}

	cout << cnt << endl;
	
	return 0;
}
