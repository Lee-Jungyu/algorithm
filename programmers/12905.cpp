#include <vector>
using namespace std;

int dp[1001][1001];

int getMin(int a, int b, int c) {
    if(a < b) {
        if (a < c) return a;
        else return c;
    }
    else {
        if(b < c) return b;
        else return c; 
    }
}

int solution(vector<vector<int>> board)
{
    int size = 0;
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j]) {
                if((i && j) == 0) 
                    dp[i][j] = 1;
                else 
                    dp[i][j] = getMin(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                
                if(size < dp[i][j]) size = dp[i][j];
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    
    return size * size;
}
