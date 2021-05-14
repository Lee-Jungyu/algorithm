#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    if(s.length() % 2) return 0;
    
    stack<int> idx_stack;
    int idx = 0;
    
    idx_stack.push(0);
    
    for(int i = 1; i < s.length(); i++) {
        if(idx_stack.size() == 0)
        {
            idx_stack.push(i);
            continue;
        }
        
        idx = idx_stack.top();
        
        if(s[idx] != s[i]) {
            idx_stack.push(i);
        }
        else {
            idx_stack.pop();
        }
    }
    
    if(idx_stack.size() == 0) return 1;

    return 0;
}
