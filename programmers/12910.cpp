#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;
	for (int i = 0; i < arr.size(); i++)
	{
		if (!(arr.at(i) % divisor)) answer.push_back(arr.at(i));
	}

	if (answer.size() == 0) answer.push_back(-1);
	else
	{
		sort(answer.begin(), answer.end());
	}
	return answer;
}
