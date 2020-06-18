#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int avg = M / budgets.size();
    
    sort(budgets.begin(), budgets.end());
    
    long long int sum = 0;
    for(int i = 0; i < budgets.size(); i++) sum += budgets[i];
    
    if(sum <= M) return budgets[budgets.size() - 1];
    
    int _min = avg;
    int _max = budgets[budgets.size() - 1];
    int _tmp = 0;
    
    while(true) {
        int _middle = (_min + _max) / 2;
        sum = 0;
        
        for(int i = 0; i < budgets.size(); i++) {
            if(budgets[i] < _middle) sum += budgets[i];
            else sum += _middle;
            
            if(sum > M) break;
        }
        
        if(_tmp == _middle) return _middle;
        
        if(sum > M) _max = _middle;
        else _min = _middle;
        
        _tmp = _middle;
    }
    
    return answer;
}

//이분탐색
