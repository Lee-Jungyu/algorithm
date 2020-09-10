#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') s[i] = 'a' + (s[i] - 'a' + n) % 26;
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] = 'A' + (s[i] - 'A' + n) % 26;
    }
    return s;
}
