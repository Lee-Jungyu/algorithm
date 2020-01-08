#include <iostream>
#include <string.h>
using namespace std;

char word[100];
bool flag[26];
int cnt = 0;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%s", word);
		for (int j = 0; j < 26; j++) flag[j] = false;

		int length = strlen(word);
		if (length == 1 || length == 2) { cnt++; continue; }

		for (int j = 0; j < length - 1; j++) 
		{
			if (word[j] != word[j + 1]) {
				if (!flag[word[j] - 'a']) flag[word[j] - 'a'] = true;
				else break;
				if (flag[word[j + 1] - 'a']) break;
			}

			if (j == length - 2) {
				cnt++;
			}
		}
	}


	printf("%d\n", cnt);

}
