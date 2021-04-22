#include <string>
#include <vector>
#include <math.h>

using namespace std;

int getNumber(vector<bool> digit) {
    int sum = 0;
    for(int i = 0; i < digit.size(); i++) {
        sum += digit[i] * pow(2, i);
    }
    return sum;
}

vector<bool> getDigit(int num) {
    vector<bool> digit(30);
    
    int idx = 0;
    while(num) {
        if(num % 2 == 1) digit[idx] = true;
        idx++;
        num /= 2;
    }
    
    return digit;
}

int getNextNumber(vector<bool> digit) {
    bool flag = false;
    int first_idx = 0;
    
    for(int i = 0; i < digit.size(); i++) {
        if(flag && !digit[i]) {
            first_idx = i - 1;
            break;
        }
        else if(!flag && digit[i]) flag = true;
        else continue;
    }
    
    int second_idx = 0;
    for(int i = first_idx; i < digit.size(); i++) {
        if(digit[i]) continue;
        second_idx = i;
        break;
    }
    
    digit[first_idx] = false;
    digit[second_idx] = true;
    
    int one_cnt = 0;
    for(int i = 0; i < second_idx; i++) {
        if(digit[i]) one_cnt++;
    }
    
    for(int i = 0; i < second_idx; i++) {
        if(one_cnt) {
            digit[i] = true;
            one_cnt--;
        }
        else digit[i] = false;
    }
    
    return getNumber(digit);
}

int solution(int n) {
    int answer = 0;
    
    vector<bool> digit = getDigit(n);
    
    return getNextNumber(digit);
}

// 이진수 배열 속 1의 개수는 같아야 하므로 1의 위치만 이동시키면 됨
// 이진수 배열의 가장 낮은 숫자 인덱스부터 처음으로 연속된 1의 마지막 인덱스를 구함 -> first_idx
// first_idx이후 처음으로 1이 아닌 인덱스를 구함 -> second_idx;
// first_idx의 1을 second_idx로 옮기고 second_idx보다 낮은 숫자 인덱스의 1을 가장 낮은 숫자 인덱스부터 채워넣음
// ex 1) 78(1001110) -> 1010110 -> 83(1010011)
// ex 2) 92(1011100) -> 1101100 -> 99(1100011)
