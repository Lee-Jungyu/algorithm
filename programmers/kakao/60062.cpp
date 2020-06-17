#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int min_value = 99;

bool cmp(int a, int b)
{
    return a > b;
}

void perm(int n,vector<int> weak, vector<int> dist, int cnt, int idx, bool dir) 
{
    //시계방향 체크
    if(cnt == idx) {
        int loc_idx = 0;
        int visited_cnt = 0;
        
        if(dir) {
            for(int k = 0; k < cnt; k++) {
                int rest_dist = dist[k];
                bool flag = false;
                
                while(true) {
                    int curr_loc = weak[loc_idx];
                    int next_loc = weak[(loc_idx + 1) % weak.size()];
                    int next_dist = next_loc - curr_loc;

                    if(curr_loc > next_loc) next_dist = next_loc + n - curr_loc;

                    visited_cnt++;
                    loc_idx = (loc_idx + 1) % weak.size();

                    if(visited_cnt == weak.size()) {
                        if(min_value > k + 1) min_value = k + 1;
                        flag = true;
                        break;
                    }
                    if(rest_dist - next_dist < 0) break;

                    rest_dist -= next_dist;
                }
                
                if(flag) break;
            }
        }
        //반시계방향 체크
        else {
            for(int k = 0; k < cnt; k++) {
                int rest_dist = dist[k];
                bool flag = false;
                
                while(true) {
                    int curr_loc = weak[loc_idx];
                    int next_loc = weak[(loc_idx + weak.size() - 1) % weak.size()];
                    int next_dist = curr_loc - next_loc;

                    if(curr_loc < next_loc) next_dist = curr_loc + n - next_loc;

                    visited_cnt++;
                    loc_idx = (loc_idx + weak.size() - 1) % weak.size();

                    if(visited_cnt == weak.size()) {
                        if(min_value > k + 1) min_value = k + 1;
                        flag = true;
                        break;
                    }
                    if(rest_dist - next_dist < 0) break;

                    rest_dist -= next_dist;
                }
                
                if(flag) break;
            }
        }
    }
    
    for(int i = idx; i < dist.size(); i++) {
        swap(dist[idx], dist[i]);
        perm(n, weak, dist, cnt, idx + 1, dir);
        swap(dist[idx], dist[i]);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    
    sort(dist.begin(), dist.end(), cmp);
    
    for(int i = 1; i <= dist.size(); i++) {
        for(int j = 0; j < weak.size(); j++) {
            perm(n, weak, dist, i, 0, true);
            perm(n, weak, dist, i, 0, false);
            
            int tmp = weak[0];
            weak.erase(weak.begin());
            weak.push_back(tmp);
        }
    }
    
    return min_value == 99 ? -1 : min_value;
}
