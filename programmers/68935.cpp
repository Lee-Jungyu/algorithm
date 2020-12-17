#include <string>
#include <vector>

using namespace std;

string reverse_ternary(int num) {
    string str = "";
    
    while(num) {
        str += (char)(num % 3 + '0');
        num /= 3;
    }
    
    return str;
}

int ternary_to_decimal(string str) {
    int n = 0;
    
    for(int i = 0; i < str.length(); i++) {
        n *= 3;
        n += str[i] - '0';
    }
    
    return n;
}

int solution(int n) {
    string str = reverse_ternary(n);
    int answer = ternary_to_decimal(str);
    return answer;
}
