#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> map;

bool findQueen(int x, int y, int n) {
    // left top
    int cx = x - 1;
    int cy = y - 1;
    while(cx >= 0 && cy >= 0) {
        if(map[cx][cy]) return true;
        cx--;
        cy--;
    }
    
    // top
    cx = x - 1;
    cy = y;
    
    while(cx >= 0) {
        if(map[cx][cy]) return true;
        cx--;
    }
    
    // right top
    cx = x - 1;
    cy = y + 1;
    
    while(cx >= 0 && cy < n) {
        if(map[cx][cy]) return true;
        cx--;
        cy++;
    }
    
    return false;
}

void setQueen(int x, int y, int n, int& answer) {
    if(findQueen(x, y, n)) return;
    
    map[x][y] = 1;
    
    if(x == n - 1) {
        answer++;
        map[x][y] = 0;
        return;
    }
    
    for(int j = 0; j < n; j++) {
        setQueen(x + 1, j, n, answer);
    }
    map[x][y] = 0;
}

int solution(int n) {
    int answer = 0;
    
    map.resize(n, vector<bool>(n, 0));
    
    for(int j = 0; j < n; j++) {
        setQueen(0, j, n, answer);
    }
    
    return answer;
}
