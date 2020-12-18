#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Ladder {
    int section1;
    int section2;
    int height;
};

vector<vector<int>> maps;
vector<vector<int>> section;
vector<vector<bool>> boundary;
map<pair<int, int>, int> ladder_hash;
vector<Ladder> ladder;
int section_cnt = 0;


void devide_section(int x, int y, int height) {
    
    section_cnt++;
    
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    section[x][y] = section_cnt;
    
    while(!q.empty()) {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int tmp_x = curr_x + dx[i];
            int tmp_y = curr_y + dy[i];
            
            if(tmp_x < 0 || tmp_x >= maps.size() || tmp_y < 0 || tmp_y >= maps.size()) continue;
            if(section[tmp_x][tmp_y] != 0) continue;
            if(maps[tmp_x][tmp_y] > maps[curr_x][curr_y] + height) continue;
            if(maps[tmp_x][tmp_y] < maps[curr_x][curr_y] - height) continue;
            
            q.push(make_pair(tmp_x, tmp_y));
            section[tmp_x][tmp_y] = section_cnt;
        }
    }
}

void get_min_ladder() {
    
    for(int x = 0; x < maps.size(); x++) {
        for(int y = 0; y < maps.size(); y++) {
            if(!boundary[x][y]) continue;
            
            for(int i = 0; i < 4; i++) {
                int tmp_x = x + dx[i];
                int tmp_y = y + dy[i];

                if(tmp_x < 0 || tmp_x >= maps.size() || tmp_y < 0 || tmp_y >= maps.size()) continue;
                
                int s1 = section[x][y];
                int s2 = section[tmp_x][tmp_y];
                
                if(s1 == s2) continue;
                
                int dist = abs(maps[x][y] - maps[tmp_x][tmp_y]);
                
                if(ladder_hash[{s1,s2}] > dist || ladder_hash[{s1,s2}] == 0) {
                    ladder_hash[{s1,s2}] = dist;
                    ladder_hash[{s2,s1}] = dist;
                }
            }
        }
    }
    
    for(auto iter = ladder_hash.begin(); iter != ladder_hash.end(); iter++) {
        if(iter->second != 0) {
            Ladder l;
            l.section1 = iter->first.first;
            l.section2 = iter->first.second;
            l.height = iter->second;

            ladder.push_back(l);
        }
    }
    
}

bool cmp(Ladder l1, Ladder l2) {
    return l1.height < l2.height;
}

int link_section() {
    int sum = 0;
    vector<int> parent(section_cnt + 1, 0);
    for(int i = 1; i <= section_cnt; i++) parent[i] = i;
    
    for(int i = 0; i < ladder.size(); i++) {
        Ladder l = ladder[i];
        int s1 = l.section1;
        int s2 = l.section2;
        
        //find parent
        int p1 = s1;
        int p2 = s2;
        while(parent[p1] != p1) p1 = parent[p1];
        while(parent[p2] != p2) p2 = parent[p2];
        
        if(p1 == p2) continue;
        sum += l.height;
        
        //union
        parent[p2] = p1;
    }
    
    return sum;
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int N = land.size();
    
    maps.assign(land.begin(), land.end());
    section.assign(N, vector<int>(N, 0));
    boundary.assign(N, vector<bool>(N, false));
    
    //devide section
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(section[i][j] == 0) {
                devide_section(i, j, height);
            }
        }
    }
    
    //set boundary
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            bool check = false;
            if(boundary[i][j]) continue;
            
            for(int k = 0; k < 4; k++) {
                int tmp_x = i + dx[k];
                int tmp_y = j + dy[k];
                
                if(tmp_x < 0 || tmp_x >= N || tmp_y < 0 || tmp_y >= N) continue;
                if(section[tmp_x][tmp_y] != section[i][j]) {
                    boundary[i][j] = true;
                    boundary[tmp_x][tmp_y] = true;
                }
            }
        }
    }
    
    //get min ladder value
    get_min_ladder();
    
    //kruscal
    sort(ladder.begin(), ladder.end(), cmp);
    answer = link_section();
    
    return answer;
}
