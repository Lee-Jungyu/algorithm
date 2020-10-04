#include <string>
#include <vector>

using namespace std;

int graph[101][101];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i = 0; i < results.size(); i++) {
        graph[results[i][0]][results[i][1]] = 1;
        graph[results[i][1]][results[i][0]] = -1;
    }
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(graph[i][k] == 1 && graph[k][j] == 1) graph[i][j] = 1;
                if(graph[i][k] == -1 && graph[k][j] == -1) graph[i][j] = -1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        bool check = true;
        for(int j = 1; j <= n; j++) {
            if(graph[i][j] == 0 && i != j) {
                check = false;
                break;
            }
        }
        if(check) answer++;
    }
    return answer;
}
