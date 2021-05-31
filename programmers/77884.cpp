#include <string>
#include <vector>

using namespace std;

int getMeasureCnt(int num) {
    if(num == 1) return 1;
  
    int cnt = 2;
    for(int i = 2; i <= num / 2; i++) {
        if(num % i == 0) cnt++;
    }
    
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; i++) {
        int measure_cnt = getMeasureCnt(i);
        if(measure_cnt % 2) answer -= i;
        else answer += i;
    }
    
    return answer;
}
