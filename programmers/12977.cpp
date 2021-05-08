#include <vector>
using namespace std;

bool primeNumber[3001];
vector<int> numArray;
int answer = 0;
void dfs(int cnt, int size, int idx, int sum) {
    sum += numArray[idx];
    
    if(cnt == size) {
        if(primeNumber[sum]) answer++;
        return;
    }
    
    for(int i = idx + 1; i < numArray.size(); i++) {
        dfs(cnt + 1, size, i, sum);
    }
}

int solution(vector<int> nums) {
    int size = 3000;

    numArray = nums;
    
    for(int i = 0; i <= size; i++) primeNumber[i] = true;
    
    for(int i = 2; i <= size; i++) {
        if(!primeNumber[i]) continue;
        for(int j = i * 2; j <= size; j += i) {
            primeNumber[j] = false;
        }
    }
    
    for(int i = 0; i < nums.size(); i++) {
        dfs(1, 3, i, 0);
    }
    
 
    return answer;
}
