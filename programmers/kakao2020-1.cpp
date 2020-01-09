#include <string>
#include <vector>
using namespace std;

string int2str(int num) {
	string result = "";
	while (num) {

		int n = num % 10;
		result += (char)(n + '0');
		num /= 10;
	}

	for (int i = 0; i < result.length() / 2; i++) {
		swap(result[i], result[result.length() - i - 1]);
	}

	if (result == "1") return "";
	return result;
}

int solution(string s) {
	int answer = 9999;
    if(s.length() == 1) return 1;
	for (int t = 1; t <= s.length() / 2; t++) {
		string str = "";
		
		for (int i = 0; ; ) {
			string token = s.substr(i, t);
			int cnt = 0;
			bool check = false;
			for (int j = i; ;) {
				string nextToken = "";
				if (j > s.length() - t + 1) {
					for (int k = j; k < s.length(); k++) {
						nextToken += s[k];
					}
				}
				else {
					nextToken = s.substr(j, t);
				}

				if (token.compare(nextToken) == 0) {
					j += t;
					cnt++;
				}

				else {
					if (cnt > 1) {
						str += int2str(cnt);
						str += token;
						i = j;
					}
					else {
						str += token;
						i += t;
					}

					break;
				}

				if (i >= s.length() - t) {
					check = true;
					for (int k = i; k < s.length(); k++)
						str += s[k];
					break;
				}
			}

			if (check) break;
		}
		if (answer > str.length()) answer = str.length();

	}


	return answer;
}
