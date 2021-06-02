#include <string>
#include <vector>

using namespace std;

string getBinary(long long num) {
    string bin = "";
    while(num) {
        bin = (char)((num % 2) + '0') + bin;
        num /= 2;
    }
    
    bin = '0' + bin;
    
    return bin;
}

string getResultBin(string bin) {
    bool check_first_one = false;
    for(int i = bin.length() - 1; i >= 0; i--) {
        if(bin[i] == '1') continue;
        
        bin[i] = '1';
        if(i != bin.length() - 1) bin[i + 1] = '0';
        break;
    }
    
    return bin;
}

long long getDecimal(string str) {
    long long result = 0;
    for(int i = 0; i < str.length(); i++) {
        result *= 2;
        result += str[i] - '0';
    }
    
    return result;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] % 2 == 0) answer.push_back(numbers[i] + 1);
        else {
            string bin = getBinary(numbers[i]);
            string result_bin = getResultBin(bin);
            
            long long result = getDecimal(result_bin);
            answer.push_back(result);
        }
    }
    
    return answer;
}

// 비트마스크 공부하면 비트마스크로도 풀 수 있을듯
