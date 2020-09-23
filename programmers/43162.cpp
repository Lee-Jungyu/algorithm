#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            answer++;
            queue<int> q;
            visited[i] = true;
            q.push(i);
            
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                
                for(int j = 0; j < n; j++) {
                    if(curr == j || visited[j]) continue;
                    if(computers[curr][j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
    
    return answer;
}
