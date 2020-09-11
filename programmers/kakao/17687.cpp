#include <string>
#include <vector>

using namespace std;

char charArr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string getNumber(int n, int number) {
    string result = "";
    
    if(number == 0) return "0";
    if(number == 1) return "1";
    
    while(number) {
        int tmp = number % n;
        result += charArr[tmp];
        number /= n;
    }
    
    for(int i = 0; i < result.length() / 2; i++) {
        char tmp = result[i];
        result[i] = result[result.length() - 1 - i];
        result[result.length() - 1 - i] = tmp;
    }
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "";
    for(int i = 0; i < t * m + p; i++)
        tmp += getNumber(n, i);
    
    for(int i = 0; i < t; i++) 
        answer += tmp[p - 1 + i * m];
    
    return answer;
}
