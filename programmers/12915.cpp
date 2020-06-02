#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	
	vector<string> answer;
	for (int i = 0; i < strings.size(); i++)
	{
		string s = strings.at(i)[n] + strings.at(i);
		answer.push_back(s);
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++)
	{
		answer.at(i) = answer.at(i).substr(1, answer.at(i).length() - 1);
	}
	return answer;
}
