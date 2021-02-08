#include <iostream>
using namespace std;

int dp[51][51][51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int t = 0; t < 2; t++){
        for(int i = 0; i < 51; i++) {
            for(int j = 0; j < 51; j++) {
                for(int k = 0; k < 51; k++) {
                    if(i == 0 || j == 0 || k == 0) dp[i][j][k] = 1;
                    else if(i > 20 || j > 20 || k > 20) 
                        dp[i][j][k] = dp[20][20][20];
                    else if(i < j && j < k) 
                        dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
                    else
                        dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
                }
            }
        }
    }

    while(true) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == -1 && b == -1 && c == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        if(a <= 0 || b <= 0 || c <= 0) cout << dp[0][0][0] << '\n';
        else cout << dp[a][b][c] << '\n';
    }

    return 0;
}
