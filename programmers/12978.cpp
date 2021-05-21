#include <vector>
#define INF 0xffffff
using namespace std;

int dist[51];
bool visited[51];
vector<vector<pair<int, int>>> map;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    // init
    map.resize(N + 1, vector<pair<int, int>>(0));
    
    for(int i = 0; i < road.size(); i++) {
        map[road[i][0]].push_back({road[i][1], road[i][2]});
        map[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    for(int i = 1; i <= N; i++) dist[i] = INF;
    
    
    // dijkstra
    int start = 1;
    
    dist[start] = 0;
    
    int curr = start;
    int next = -1;
    while(next != curr) {
        if(next != -1) curr = next;
        
        visited[curr] = true;
        
        for(int i = 0; i < map[curr].size(); i++) {
            int linked = map[curr][i].first;
            if(visited[linked]) continue;
            int linked_cost = map[curr][i].second;
            if(dist[linked] > dist[curr] + linked_cost) {
                dist[linked] = dist[curr] + linked_cost;
            }
        }
        
        next = curr;
        for(int i = 1; i <= N; i++) {
            if(next == curr && !visited[i] && dist[i] != INF) next = i;
            else if(!visited[i] && dist[i] < dist[next]) next = i;
        }
    }
    
    // result
    for(int i = 1; i <= N; i++) {
        if(dist[i] <= K) answer++;
    }
    
    return answer;
}
