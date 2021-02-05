#include <string>
#include <vector>
#define INF 0xfffffff
using namespace std;

vector<vector<int>> dist(201, vector<int>(201, INF));

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(int i = 0; i < fares.size(); i++) {
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(dist[j][k] > dist[j][i] + dist[i][k] ) dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(dist[s][i] == INF || dist[i][a] == INF || dist[i][a] == INF) continue;
        if(dist[s][i] + dist[i][a] + dist[i][b] < answer)
            answer = dist[s][i] + dist[i][a] + dist[i][b];
    }
    
    return answer;
}
