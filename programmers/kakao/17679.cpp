#include <string>
#include <vector>

using namespace std;

int answer;
int N, M;
vector<string> map;

void downBlock() {
    for(int j = 0; j < M; j++) {
        for(int i = N - 1; i >= 0; i--) {
            if(map[i][j] == ' ') {
                for(int k = i; k >= 0; k--) {
                    if(map[k][j] != ' ') {
                        swap(map[i][j], map[k][j]);
                        break;
                    }
                }
            }
        }        
    }
}

void eraseBlock(vector<pair<int, int>> vec) {
    auto iter = vec.begin();
    for(auto iter = vec.begin(); iter != vec.end(); iter++) {
        int i = iter->first;
        int j = iter->second;
        
        if(map[i][j] != ' ') {
            answer++;
            map[i][j] = ' ';
        }
        if(map[i + 1][j] != ' ') {
            answer++;
            map[i + 1][j] = ' ';
        }
        if(map[i][j + 1] != ' ') {
            answer++;
            map[i][j + 1] = ' ';
        }
        if(map[i + 1][j + 1] != ' ') {
            answer++;
            map[i + 1][j + 1] = ' ';
        }
    }
}

vector<pair<int, int>> getBlockPose() {
    vector<pair<int, int>> result;
    
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = 0; j < M - 1; j++)
        {
            if(map[i][j] == ' ') continue;
            if(map[i][j] == map[i + 1][j] && map[i][j] == map[i][j + 1] && map[i][j] == map[i + 1][j + 1]) {
                result.push_back(make_pair(i, j));
            }
        }
    }
    return result;
}

int solution(int n, int m, vector<string> board) {
    answer = 0;
    N = n;
    M = m;
    map = board;
    
    while(true) {
        vector<pair<int, int>> vec = getBlockPose();
        
        if(vec.size() == 0) 
            break;
        
        eraseBlock(vec);
        downBlock();
    }
    
    return answer;
}
