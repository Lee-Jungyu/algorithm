#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool negative = false;
    if(s[0] == '+' || s[0] == '-') {
        if(s[0] == '-') negative = true;
        for(int i = 1; i < s.length(); i++) {
            answer *= 10;
            answer += s[i] - '0';
        }
    }
    else {
        for(int i = 0; i < s.length(); i++) {
            answer *= 10;
            answer += s[i] - '0';
        }
    }
    
    if(negative) return -1 * answer;
    return answer;
}
