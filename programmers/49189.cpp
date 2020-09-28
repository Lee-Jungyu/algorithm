#include <string>
#include <vector>
#include <queue>
using namespace std;

bool map[20001][20001];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max = 0;
    vector<int> dist(n + 1, 99999);
    
    for(int i = 0; i < edge.size(); i++) {
        map[edge[i][0]][edge[i][1]] = true;
        map[edge[i][1]][edge[i][0]] = true;
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty()) {
        int num = q.front();
        int d = dist[num] + 1;
        q.pop();
        for(int i = 2; i <= n; i++) {
            if(map[num][i] && dist[i] > d) {
                q.push(i);
                dist[i] = d;
                if(max < dist[i]) max = dist[i];
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(max == dist[i]) answer++;
    }
    
    return answer;
}
