#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long _min = times[0];
    long long _max = times[times.size() - 1] * n;
    
    while(true) {
        long long _middle = (_min + _max) / 2;
        long long sum = 0;
        
        for(int i = 0; i < times.size(); i++) sum += _middle / times[i];
        
        if(_min > _max) return _min;
        
        if(n > sum) _min = _middle + 1;
        else _max = _middle - 1;
    }
    
    return answer;
}
//이분탐색
