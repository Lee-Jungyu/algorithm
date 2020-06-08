#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> possible(n, 1);
    
    for(int i = 0; i < lost.size(); i++) {
        possible[lost[i] - 1] -= 1;
    }
    
    for(int i = 0; i < reserve.size(); i++) {
        possible[reserve[i] - 1] += 1;
    }
    
    for(int i = 0; i < n; i++) {
        if(i >= 1 && possible[i] == 2) {
            if(possible[i - 1] == 0) {
                possible[i - 1] = possible[i] = 1;
                continue;
            }
        }
        if(i < n - 1 && possible[i] == 2) {
            if(possible[i + 1] == 0) {
                possible[i + 1] = possible[i] = 1;
                continue;
            }
        }
    }
    
    int cnt = n;
    for(int i = 0; i < n; i++) {
        if(possible[i] == 0) cnt--;
    }    
    return cnt;
}
