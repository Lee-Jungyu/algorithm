#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int work[2000][2];

int str2int(string str)
{
	int result = 0;
	for (int i = 0; i < str.length(); i++)
	{
		result += str[i] - '0';
		if (i != str.length() - 1) {
			result *= 10;
		}
	}

	return result;
}

int time2milisec(string str, string during)
{
	//hh:mm:ss.sss -> ss*1000 + mm*60000 + hh * 3600000
	string strhh = "";
	strhh = strhh + str[0] + str[1];
	string strmm = "";
	strmm = strmm + str[3] + str[4];
	string strss = "";
	strss = strss + str[6] + str[7];
	string strsss = "";
	strsss = strsss + str[9] + str[10] + str[11];

	int hh = str2int(strhh) * 3600000;
	int mm = str2int(strmm) * 60000;
	int ss = str2int(strss) * 1000;
	int sss = str2int(strsss);

	if (during.length() == 1) {
		sss -= (str2int(during) * 1000);
	}
	else {
		sss -= (str2int(during.substr(0, 1)) * 1000);
		sss -= str2int(during.substr(2, during.length() - 2));
	}
	int result = hh + mm + ss + sss;
	return result;
}

int solution(vector<string> lines)
{
	int answer = 0;
	N = lines.size();

	for (int i = 0; i < N; i++)
	{
		string time = lines[i].substr(11, 12);
		string during = lines[i].substr(24, lines[i].find_first_of('s') - 24);

		work[i][1] = time2milisec(time, "0");
		work[i][0] = time2milisec(time, during) + 1;

	}

	int lasttime = 0;
	for (int i = 0; i < N; i++)
	{
		if (lasttime < work[i][1]) lasttime = work[i][1];
	}

	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		tmp = 0;

		for (int j = 0; j < N; j++)
		{
			if (work[i][0] - 999 <= work[j][0] && work[j][0] <= work[i][0]) {
				tmp++;
			}
			else if (work[i][0] - 999 <= work[j][1] && work[j][1] <= work[i][0]) {
				tmp++;
			}
			else if (work[j][0] <= work[i][0] - 999 && work[i][0] < work[j][1]) {
				tmp++;
			}
		}

		if (tmp > answer) answer = tmp;
	}
	return answer;
}

