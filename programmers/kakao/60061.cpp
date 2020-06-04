#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//build_frame = {x, y, a, b} x,y:가로(열), 세로(행) a:0->기둥 1->보 b:0->설치 1->삭제
int g[105][105];
int b[105][105];

void building(int x, int y, int a)
{
    //보
    if(a) {
        //밑에 기둥이 있는 경우
        if(g[y - 1][x] || g[y - 1][x + 1]) {
            b[y][x] = 1;
            return;
        }
        //양옆에 보가 있는 경우
        else {
            if(x != 0) {
                if(b[y][x - 1] && b[y][x + 1]) {
                    b[y][x] = 1;
                    return;
                }
            }
        }
    }
    //기둥
    else {
        //바닥인 경우
        if(y == 0) {
            g[y][x] = 1;
            return;
        }
        //밑에 보가 있거나 기둥이 있는 경우
        else {
            if(x != 0) {
                if(g[y - 1][x] || b[y][x] || b[y][x - 1]) {
                    g[y][x] = 1;
                    return;
                }
            }
            else {
                if(g[y - 1][x] || b[y][x]) {
                    g[y][x] = 1;
                    return;
                }
            }
        }
    }
}

void destroying(int x, int y, int a)
{
    //보
    if(a) {
        //보의 왼쪽에 기둥이 있을 경우
        if(g[y][x]) {
            if(x == 0) {
                if(!g[y - 1][x]) {
                    return;
                }
            }
            else {
                if(!g[y - 1][x] && !b[y][x - 1]) {
                    return;
                }
            }
        }
        //보의 오른쪽에 기둥이 있을 경우
        if(g[y][x + 1]) {
            if(!g[y - 1][x + 1] && !b[y][x + 1]) {
                return;
            }
        }
        //보의 오른쪽에 보가 있을 경우
        if(b[y][x + 1]) {
            if(!g[y - 1][x + 1] && !g[y - 1][x + 2]) {
                return;
            }
        }
        //보의 왼쪽에 보가 있을 경우
        if(x != 0) {
            if(b[y][x - 1]) {
                if(!g[y - 1][x - 1] && !g[y - 1][x]) {
                    return;
                }
            }
        }
        b[y][x] = 0;
    }
    //기둥
    else {
        //기둥위에 기둥이 있을 때
        if(g[y + 1][x]) {
            if(x != 0) {
                if(!b[y + 1][x] && !b[y + 1][x - 1]) {
                    return;
                }
            }
            else {
                if(!b[y + 1][x]) {
                    return;
                }
            }
        }
        //기둥 오른쪽 위에 보가 있을 때
        if(b[y + 1][x]) {
            if(x == 0) {
                if(!g[y][x + 1]) {
                    return;
                }
            }
            else {
                if(!g[y][x + 1] && !(b[y + 1][x - 1] && b[y + 1][x + 1]) ) {
                    return;
                }
            }
        }
        //기둥 왼쪽 위에 보가 있을 때
        if(x != 0) {
            if(b[y + 1][x - 1]) {
                if(x == 1) {
                    if(!g[y][x - 1]) {
                        return;
                    }
                }
                else {
                    if(!g[y][x - 1] && !(b[y + 1][x - 2] && b[y + 1][x])) {
                        return;
                    }
                }
            }
        }
        g[y][x] = 0;
    }
}

bool cmp(vector<int> a, vector<int> b)
{
    if(a[0] == b[0]) {
        if(a[1] == b[1]) {
            return a[2] < b[2];
        }
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for(int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        
        if(b) building(x,y,a);
        else destroying(x,y,a);
    }
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(b[i][j]) {
                answer.push_back({j, i, 1});
            }
            if(g[i][j]) {
                answer.push_back({j, i, 0});
            }
        }
    }
    
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}
