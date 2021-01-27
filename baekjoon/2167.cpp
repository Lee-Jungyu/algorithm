#include <iostream>
using namespace std;

int arr[301][301];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int num;
            cin >> num;
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + num;
        }
    }

    int k;
    cin >> k;

    while(k--) {
        int i,j,x,y;
        cin >> i >> j >> x >> y;
        cout << arr[x][y] - arr[i - 1][y] - arr[x][j - 1] + arr[i - 1][j - 1] << endl;
    }
    
    return 0;
}
