#include <string>
#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
enum FRIENDS { A, C, F, J, M, N, R, T };
int pose[8];
bool visited[8] = {false, };
int result;

int getFriendNo(char c) {
    switch(c) {
        case 'A':
            return A;
        case 'C':
            return C;
        case 'F':
            return F;
        case 'J':
            return J;
        case 'M':
            return M;
        case 'N':
            return N;
        case 'R':
            return R;
        case 'T':
            return T;
    }
}

int getAbsoluteDist(int a, int b) {
    if(a > b) return a - b - 1;
    else return b - a - 1;
}

void dfs(int n, int cnt, vector<string> data)
{
    pose[cnt - 1] = n;
    if(cnt == 8) {
        int size = data.size();
        
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < data[i].length(); j++) {
                int f1 = getFriendNo(data[i][0]);
                int f2 = getFriendNo(data[i][2]);
                
                int pose1, pose2;
                for(int k = 0; k < 8; k++) {
                    if(pose[k] == f1) pose1 = k;
                    if(pose[k] == f2) pose2 = k;
                }
                
                if(data[i][3] == '=') {
                    if(getAbsoluteDist(pose1, pose2) != data[i][4] - '0') return;
                }
                else if(data[i][3] == '<') {
                    if(getAbsoluteDist(pose1, pose2) >= data[i][4] - '0') return;
                }
                else if(data[i][3] == '>') {
                    if(getAbsoluteDist(pose1, pose2) <= data[i][4] - '0') return;
                }
            }
        }
        
        result++;
    }
    
    for(int i = 0; i < 8; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i, cnt + 1, data);
            visited[i] = false;
        }
    }
}

int solution(int n, vector<string> data) {
    result = 0;
    
    for(int i = 0; i < 8; i++) {
        visited[i] = true;
        dfs(i, 1, data);
        visited[i] = false;
    }
    
    return result;
}
