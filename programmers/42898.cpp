#include <string>
#include <vector>

using namespace std;

int map[101][101] = {{0,},};
int dp[101][101] = {{0,},};
int solution(int m, int n, vector<vector<int>> puddles) {
    
    for(int i = 0; i < puddles.size(); i++) {
        map[puddles[i][1] - 1][puddles[i][0] - 1] = 1;
    }
    
    for(int i = 0; i < n; i++) {
        if(map[i][0] == 1) break;
        dp[i][0] = 1;
    }
    
    for(int j = 0; j < m; j++) {
        if(map[0][j] == 1) break;
        dp[0][j] = 1;
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(map[i][j] == 1) continue;
            dp[i][j] = (dp[i - 1][j] % 1000000007 + dp[i][j - 1] % 1000000007) % 1000000007;
        }
    }
    
    return dp[n - 1][m - 1];
}
