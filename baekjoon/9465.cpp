#include <iostream>
using namespace std;

int arr[2][100001];
int dp[2][100001];

int get_max(int n, int m) {
    if (n > m) return n;
    return m;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];

        for(int i = 1; i < n; i++) {
            dp[0][i] = get_max(dp[1][i - 1] + arr[0][i], dp[0][i - 1]);
            dp[1][i] = get_max(dp[0][i - 1] + arr[1][i], dp[1][i - 1]);
        }
        
        cout << get_max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }

    return 0;
} 
