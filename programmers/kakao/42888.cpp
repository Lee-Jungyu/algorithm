#include <string>
#include <vector>

using namespace std;

string id[100000];
string name[100000];
int cnt = 0;

string toString(int s) {
	string result = "";
	if (s == 0) return "0";
	while (s != 0) {
		result = (char)((s % 10) + '0') + result;
		s /= 10;
	}
	return result;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	string rid;
	string nn;
	for (int i = 0; i < record.size(); i++)
	{
		rid = "";
		nn = "";
		if (record.at(i)[0] == 'E') { //Enter
			int j;
			int idx = cnt;
			for (j = 6; j < record.at(i).length(); j++) {
				if (record.at(i)[j] == ' ') { break; }
				rid += record.at(i)[j];
			}
			bool already = false;
			int k;
			for (k = 0; k < cnt; k++) {
				if (id[k] == rid) {
					already = true;
					break;
				}
			}
			if (already == false) {

				id[cnt] = rid;
				int a = j;
				for (j = a + 1; j < record.at(i).length(); j++) {
					nn += record.at(i)[j];
				}
				name[cnt++] = nn;
				answer.push_back(toString(idx) + " 님이 들어왔습니다.");
			}
			else {
				for (int l = j + 1; l < record.at(i).length(); l++) {
					nn += record.at(i)[l];
				}
				name[k] = nn;
				answer.push_back(toString(k) + " 님이 들어왔습니다.");
			}
		}

		else if (record.at(i)[0] == 'L') { //Leave
			for (int j = 6; j < record.at(i).length(); j++) {
				if (record.at(i)[j] == ' ') { break; }
				rid += record.at(i)[j];
			}
			int idx = 0;
			for (int j = 0; j < cnt; j++) {
				if (id[j] == rid) {
					idx = j;
				}
			}
			answer.push_back(toString(idx) + " 님이 나갔습니다.");
		}

		else { //Change
			int j;
			for (j = 7; j < record.at(i).length(); j++) {
				if (record.at(i)[j] == ' ') { break; }
				rid += record.at(i)[j];
			}
			for (int k = 0; k < cnt; k++) {
				if (id[k] == rid) {
					for (int l = j + 1; l < record.at(i).length(); l++) {
						nn += record.at(i)[l];
					}
					name[k] = nn;
				}
			}
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		string str = answer.at(i);
		int j;
		for (j = 0; j < str.length(); j++) {
			if (str[j] == ' ') {
				break;
			}
		}
		string str1 = str.substr(0, j + 0);
		string str2 = str.substr(j + 1);

		str = (name[stoi(str1)] + str2);
		answer.at(i) = str;
	}

	return answer;
}
