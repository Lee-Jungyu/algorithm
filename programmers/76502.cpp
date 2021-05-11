#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int str_size = s.length();
    
    for(int start_idx = 0; start_idx < str_size; start_idx++) {
        stack<char> st;
        bool check = true;
        for(int i = 0; i < str_size; i++) {
            int curr_idx = (start_idx + i) % str_size;
            
            if(s[curr_idx] == '(' || s[curr_idx] == '{' || s[curr_idx] == '[') {
                st.push(s[curr_idx]);
            }
            else if(s[curr_idx] == ')') {
                if(st.top() == '(') {
                    st.pop();
                    continue;
                }
                check = false;
                break;
            }
            else if(s[curr_idx] == '}') {
                if(st.top() == '{') {
                    st.pop();
                    continue;
                }
                check = false;
                break;
            }
            else if(s[curr_idx] == ']') {
                if(st.top() == '[') {
                    st.pop();
                    continue;
                }
                check = false;
                break;
            }
        }
        if(check && st.size() == 0) answer++;
    }
    
    return answer;
}
