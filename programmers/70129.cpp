#include <string>
#include <vector>

using namespace std;

int getZeroCnt(string s) {
    int cnt = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '0') cnt++; 
    }
    
    return cnt;
}

string getZeroRemoveString(int length, int zeroCnt) {
    string s = "";
    
    for(int i = 0; i < length - zeroCnt; i++) {
        s += '1';
    }
    
    return s;
}

string getBinary(int num) {
    string s = "";
    
    while(num) {
        if(num % 2) s = '1' + s;
        else s = '0' + s;
        
        num /= 2;
    }
    
    return s;
}

vector<int> solution(string s) {
    
    int cnt = 0;
    int zeroCntSum = 0;
    while(s != "1") {
        int zeroCnt = getZeroCnt(s);
        zeroCntSum += zeroCnt;
        s = getZeroRemoveString(s.length(), zeroCnt);
        s = getBinary(s.length());
        cnt++;
    }
    
    return {cnt, zeroCntSum};
}
