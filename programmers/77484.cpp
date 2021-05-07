#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    
    bool my_nums[46] = {false, };
    
    int zero_cnt = 0;
    for(int i = 0; i < lottos.size(); i++) {
        if(lottos[i] == 0) zero_cnt++;
        my_nums[lottos[i]] = true; 
    }
    
    int check_cnt = 0;
    for(int i = 0; i < win_nums.size(); i++) {
        if(my_nums[win_nums[i]]) {
            check_cnt++;
        }
    }
    
    int best = 6 - check_cnt - zero_cnt + 1;
    if(best >= 6) best = 6;
    
    int worst = 6 - check_cnt + 1;
    if(worst >= 6) worst = 6;
    
    return {best, worst};
}
