#include <string>
#include <vector>
using namespace std;

vector<vector<int>> triangle(1000, vector<int> (1000, 0));

void make_triangle(int idx, int n, int a) {
    if(n < 1) return;
    
    int x = 2 * a;
    int y = a;
    for(int i = 2 * a; i < 2 * a + n; i++) {
        triangle[i][a] = idx++;
        x = i;
    }
    for(int j = a + 1; j < a + n; j++) {
        triangle[x][j] = idx++;
        y = j;
    }
    for(int k = 1; k < n - 1; k++) {
        triangle[x - k][y - k] = idx++;
    }
    
    make_triangle(idx, n - 3, a + 1);
}

vector<int> solution(int n) {
    vector<int> answer;
    make_triangle(1, n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            answer.push_back(triangle[i][j]);
        }
    }
    
    return answer;
}
