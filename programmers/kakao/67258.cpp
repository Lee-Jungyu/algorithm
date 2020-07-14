#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> hash;
    int min_value = 100001;
    
    for(string str : gems) hash[str] = 0;
    
    int kind = hash.size();
    int curr_kind = 0;
    int s_idx = 0, e_idx = 0;
    int tmp1 = 0, tmp2 = 0;
    
    for(s_idx = 0; s_idx < gems.size(); s_idx++) {
        if(hash[gems[s_idx]] == 0) curr_kind++;
        
        hash[gems[s_idx]]++;
        
        if(curr_kind != kind) {
            continue;
        }
        
        while(e_idx < gems.size()) {
            hash[gems[e_idx]]--;
            
            e_idx++;
            if(hash[gems[e_idx - 1]] == 0) {
                curr_kind--;
                break;
            }
            
        }
        
        if(s_idx - e_idx < min_value) {
            min_value = s_idx - e_idx;
            tmp1 = e_idx;
            tmp2 = s_idx + 1;
        }
    }
    
    answer.push_back(tmp1);
    answer.push_back(tmp2);
    return answer;
}
