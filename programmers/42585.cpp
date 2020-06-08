#include <string>
#include <stack>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> s;
    
    for(int i = 0; i < arrangement.length(); i++) {
        if(arrangement[i] == '(') {
            s.push(s.size());
        }
        else {
            if(arrangement[i - 1] == '(') {
                answer += s.top();
            }
            else {
                answer += 1;
            }
            s.pop();
        }
    }
    return answer;
}
