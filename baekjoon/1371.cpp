#include <iostream>
#include <string>
using namespace std;

int cnt[26] = { 0, };

int main()
{
	string str;

	while (getline(cin, str))
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				cnt[str[i] - 'a']++;
		}
	}

	int max = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max < cnt[i]) max = cnt[i];
	}

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] == max) cout << (char)(i + 'a');
	}
}
