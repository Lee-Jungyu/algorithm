#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int sum, bool plus, int idx, int target, int& answer) {
    
    if(plus) sum += numbers[idx];
    else sum -= numbers[idx];
    
    if(idx == numbers.size() - 1) {
        if(sum == target) answer++;
        return;
    }
    
    dfs(numbers, sum, true, idx + 1, target, answer);
    dfs(numbers, sum, false, idx + 1, target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, 0, true, 0, target, answer);
    dfs(numbers, 0, false, 0, target, answer);
    
    return answer;
}
