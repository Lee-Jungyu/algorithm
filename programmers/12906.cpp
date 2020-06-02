#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	int front = -1;
	for (int i = 0; i < arr.size(); i++)
	{
		if (front != arr.at(i)) answer.push_back(arr.at(i));
		front = arr.at(i);
	}
	return answer;
}
