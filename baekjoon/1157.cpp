#include <iostream>
#include <string.h>
using namespace std;

char word[1000001];
int cnt[26] = { 0, };
int main()
{
	scanf("%s", word);
	
	int length = strlen(word);

	for (int i = 0; i < length; i++)
	{
		if (word[i] >= 97 && word[i] <= 123) {
			cnt[word[i] - 97]++;
		}
		else {
			cnt[word[i] - 65]++;
		}
	}

	bool eq = false;
	int max = 0;
	int flag = -1;
	for (int i = 0; i < 26; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			flag = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (i == flag) continue;
		if (cnt[i] == max) eq = true;
	}

	if (eq) printf("%c", '?');
	else printf("%c", flag + 65);
	
	return 0;
}
