#include <vector>
using namespace std;

int dp[100001][4];

int getMax(int row, int exclude_idx = -1) {
    int max = 0;
    for(int i = 0; i < 4; i++) {
        if(i == exclude_idx) continue;
        if(max < dp[row][i]) max = dp[row][i];
    }
    
    return max;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for(int i = 0; i < 4; i++) dp[0][i] = land[0][i];
    
    for(int i = 1; i < land.size(); i++) {
        for(int j = 0; j < 4; j++) {
            dp[i][j] = getMax(i - 1, j) + land[i][j];
        }
    }

    return getMax(land.size() - 1);
}
