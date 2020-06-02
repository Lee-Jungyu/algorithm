#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "김서방은 ";
	for (int i = 0; i < seoul.size(); i++)
	{
		if (seoul.at(i) == "Kim") {
			int n = i;
			string num = "";
			while (n != 0)
			{
				num = (char)((n % 10) + '0') + num;
				n /= 10;
			}
      if(i == 0) answer = "김서방은 0에 있다";
		  else answer = answer + num + "에 있다";
		}
	}
	return answer;
}
