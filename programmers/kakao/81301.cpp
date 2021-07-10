#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string tmp = "";
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            tmp += s[i];
        }
        else if(s[i] == 'z') {
            tmp += '0';
            i += 3;
        }
        else if(s[i] == 'o') {
            tmp += '1';
            i += 2;
        }
        else if(s[i] == 't') {
            if(s[i + 1] == 'w') {
                tmp += '2';
                i += 2;
            }
            else {
                tmp += '3';
                i += 4;
            }
        }
        else if(s[i] == 'f') {
            if(s[i + 1] == 'o') {
                tmp += '4';
                i += 3;
            }
            else {
                tmp += '5';
                i += 3;
            }
        }
        else if(s[i] == 's') {
            if(s[i + 1] == 'i') {
                tmp += '6';
                i += 2;
            }
            else {
                tmp += '7';
                i += 4;
            }
        }
        else if(s[i] == 'e') {
            tmp += '8';
            i += 4;
        }
        else {
            tmp += '9';
            i += 3;
        }
    }
    
    int answer = stoi(tmp);
    
    return answer;
}
