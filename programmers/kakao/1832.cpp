#include <vector>

using namespace std;

int MOD = 20170805;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> city_map) {
    
    vector<vector<int>> map(n + 2, vector<int> (m + 2, 0));
    
    for(int i = 0; i < n; i++) {
        if(city_map[i][0] == 1) break;
        map[i][0] = 1;
    }
    
    for(int j = 0; j < m; j++) {
        if(city_map[0][j] == 1) break;
        map[0][j] = 1;
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(map[i][j] == 1) continue;
            if(city_map[i - 1][j] == 2) {
                int k = i - 1;
                int tmp = 2;
                for(k = i - 1; k >= 0; k--) {
                    if(city_map[k][j] == 2) continue;
                    tmp = city_map[k][j];
                    if(tmp == 0 || tmp == 1) break;
                }
                if(tmp == 0) map[i][j] = (map[i][j] + map[k][j]) % MOD;
            }
            else if(city_map[i - 1][j] == 0) {
                map[i][j] = (map[i][j] + map[i - 1][j]) % MOD;
            }
            if(city_map[i][j - 1] == 2) {
                int k = j - 1;
                int tmp = 2;
                for(k = j - 1; k >= 0; k--) {
                    if(city_map[i][k] == 2) continue;
                    tmp = city_map[i][k];
                    if(tmp == 0 || tmp == 1) break;
                }
                if(tmp == 0) map[i][j] = (map[i][j] + map[i][k]) % MOD;
            }
            else if(city_map[i][j - 1] == 0) {
                map[i][j] = (map[i][j] + map[i][j - 1]) % MOD;
            }
        }
    }
    
    
    return map[n - 1][m - 1];
}
