#include <string>
#include <vector>

using namespace std;

int getMax(int a, int b) {
    return a > b ? a : b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle.size());
    for(int i = 0; i < triangle.size(); i++) {
        dp[i].resize(triangle[i].size());
    }
    
    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i < triangle.size(); i++) {
        for(int j = 0; j < triangle[i].size(); j++) {
            if(j == 0) {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            else if(j == triangle[i].size() - 1) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            else {
                dp[i][j] = getMax(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
    }
    
    for(int i = 0; i < dp[triangle.size() - 1].size(); i++) {
        answer = answer > dp[triangle.size() - 1][i] ? answer : dp[triangle.size() - 1][i];
    }
    
    return answer;
}
