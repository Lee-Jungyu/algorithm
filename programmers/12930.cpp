#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    int idx = 1;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            idx = 1;
            continue;
        }
        else {
            if(idx % 2) {
                idx++;
                if(s[i] >= 'a' && s[i] <='z') s[i] += ('A' - 'a');
            }
            else {
                idx++;
                if(s[i] >= 'A' && s[i] <='Z') s[i] += ('a' - 'A');
            }
        }
        
    }
    
    return s;
}
