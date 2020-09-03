#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int min = 1;
    int max = 200000000;
    int tmp = 0;
    
    while(true) {
        int mid = (min + max) / 2;
        if(mid == tmp) break;
        tmp = mid;
        
        int cnt = 0;
        bool check = false;
        
        for(int i = 0; i < stones.size(); i++) {
            if(stones[i] < mid) {
                cnt++;
            }
            else {
                cnt = 0;
            }
            
            if(cnt == k) {
                check = true;
                break;
            }
        }
        
        if(check) {
            max = mid - 1;
        }
        else {
            min = mid + 1;
        }
    }
    
    return tmp;
}
