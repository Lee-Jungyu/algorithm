#include <string>
#include <vector>

using namespace std;

string make_string(int cnt, string str)
{
    string s = "";
    if (cnt != 1) {
        while (cnt) {
            s = (char)((cnt % 10) + '0') + s;
            cnt /= 10;
        }
    }
    s += str;

    return s;
}

int solution(string s) {
    int answer = s.length();
    int cnt = 1;
    for (int i = 1; i <= s.length() / 2; i++)
    {
        int cnt = 1;
        string ss = "";
        string tmp = "";
        int j = 0;
        for (j = 0; j <= s.length() - i; j += i) {
            string str = "";
            for (int k = 0; k < i; k++) {
                str += s[j + k];
            }
            if (str == tmp) {
                cnt++;
            }
            else {
                ss += make_string(cnt, tmp);
                tmp = str;
                cnt = 1;
            }
        }
        ss += make_string(cnt, tmp);
        while (j != s.length()) {
            ss += s[j];
            j++;
        }
        if (answer > ss.length()) answer = ss.length();
    }
    return answer;
}
