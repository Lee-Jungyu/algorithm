#include <string>
#include <vector>

using namespace std;

int ascii[130] = { 0, };
string solution(string s) {
	string answer = "";
	for (int i = 0; i < s.length(); i++)
	{
		ascii[s[i]]++;
	}
	for (char i = 127; i >= 0; i--)
	{
		for (int j = 0; j < ascii[i]; j++)
		{
			answer += i;
		}
	}
	return answer;
}
