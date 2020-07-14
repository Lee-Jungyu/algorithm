#include <string>
#include <vector>
#include <queue>

using namespace std;

int value_map[26][26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class Pose{
public:
    int x;
    int y;
    int value;
    int dir;
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    queue<Pose> q;
    
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            value_map[i][j] = 0x7fffffff;
        
    value_map[0][0] = 0;
    Pose p1, p2;
    p1.x = p2.x = p1.y = p2.y = p1.value = p2.value = 0;
    p1.dir = 0;
    p2.dir = 1;
    
    q.push(p1);
    q.push(p2);
    
    while(!q.empty()) {
        Pose p = q.front();
        q.pop();
        
        int x = p.x;
        int y = p.y;
        int value = p.value;
        int dir = p.dir;
        
        for(int i = 0; i < 4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            int mvalue = dir == i ? value + 100 : value + 600;
            if(mx >= 0 && mx < board.size() && my >= 0 && my < board.size()) {
                if(board[mx][my] == 0 && value_map[mx][my] >= mvalue) {
                    Pose pp;
                    pp.x = mx;
                    pp.y = my;
                    pp.value = mvalue;
                    pp.dir = i;

                    q.push(pp);
                    
                    value_map[mx][my] = mvalue;
                }
            }
        }
    }
    
    return value_map[board.size() - 1][board.size() - 1];
}
