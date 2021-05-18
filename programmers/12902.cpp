#include <string>
#include <vector>

using namespace std;

long long dp[5001];
int mod = 1000000007;
int solution(int n) {
    if(n % 2) return 0;
    
    dp[2] = 3;
    
    for(int i = 4; i <= n; i += 2) {
        dp[i] += dp[i - 2] * dp[2];
        for(int j = i - 4; j > 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }
        dp[i] += 2;
        
        dp[i] = dp[i] % mod;
    }
    
    return dp[n];
}
