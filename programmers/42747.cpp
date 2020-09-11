#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    
    int max = citations.size() - 1;
    int min = 0;
    int tmp = -1;
    int answer = 0;
    
    while(true) {
        int mid = (max + min) / 2;
        
        if(mid == tmp) {
            answer = mid + 1;
            break;
        }
        
        if(citations[citations.size() - mid - 1] >= mid + 1) {
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
        tmp = mid;
    }
    
    if(citations[answer - 1] == 0) return 0;
    
    return answer;
}
