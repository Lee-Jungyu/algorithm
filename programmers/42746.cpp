#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string i2a(int number) {
    string str = "";
    if(number == 0) {
        return "0";
    }
    while(number) {
        str = (char)(number % 10 + '0') + str;
        number /= 10;
    }
    return str;
}

bool cmp(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numberstring;
    for(int i = 0; i < numbers.size(); i++)
        numberstring.push_back(i2a(numbers[i]));
    
    sort(numberstring.begin(), numberstring.end(), cmp);
    
    for(int i = 0; i < numberstring.size(); i++) 
        answer += numberstring[i];
    
    if(answer[0] == '0') return "0";
    
    return answer;
}
