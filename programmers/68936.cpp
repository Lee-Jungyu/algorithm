#include <string>
#include <vector>
#include <math.h>

using namespace std;

int zero_cnt = 0;
int one_cnt = 0;

vector<vector<int>> map;

void check_zero_one(int size, int start_x, int start_y) {
    
    if(size == 0) {
        if(map[start_x][start_y] == 0) zero_cnt++;
        else one_cnt++;
        
        return;
    }
    
    bool check = true;
    for(int i = start_x; i < start_x + pow(2, size); i++) {
        for(int j = start_y; j < start_y + pow(2, size); j++) {
            if(map[i][j] != map[start_x][start_y]) {
                check = false;
                break;
            }
        }
        
        if(!check) break;
    }
    
    if(check) {
        if(map[start_x][start_y] == 0) zero_cnt++;
        else one_cnt++;
        
        return;
    }
    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            check_zero_one(size - 1, start_x + i * pow(2, size - 1), start_y + j * pow(2, size - 1));
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    
    map.assign(arr.begin(), arr.end());
    
    int size = log(arr.size()) / log(2);
    
    check_zero_one(size, 0, 0);
    
    vector<int> answer;
    answer.push_back(zero_cnt);
    answer.push_back(one_cnt);
    return answer;
}
