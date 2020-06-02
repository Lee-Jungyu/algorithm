#include<string>

using namespace std;

int check = 0;
bool solution(string s)
{
	bool answer = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			check++;
		else
			check--;

		if (check < 0) return false;
	}
	if (check != 0) return false;
	return true;
}
