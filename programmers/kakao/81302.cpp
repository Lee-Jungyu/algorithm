#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int x;
    int y;
    int d;
};

bool bfs(vector<string> place, int x, int y) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool visited[5][5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            visited[i][j] = false;
        }
    }
    
    queue<Node> nq;
    Node n;
    n.x = x;
    n.y = y;
    n.d = 0;
    
    nq.push(n);
    visited[x][y] = true;
    
    while(!nq.empty()) {
        Node curr = nq.front();
        nq.pop();
        
        for(int i = 0; i < 4; i++) {
            int next_x = curr.x + dx[i];
            int next_y = curr.y + dy[i];
            int next_d = curr.d + 1;
            
            if(next_d > 2) break;
            if(next_x >= 0 && next_x < 5 && next_y >= 0 && next_y < 5) {
                if(visited[next_x][next_y]) continue;
                if(place[next_x][next_y] == 'O') {
                    Node newNode;
                    newNode.x = next_x;
                    newNode.y = next_y;
                    newNode.d = next_d;
                    
                    nq.push(newNode);
                }
                else if(place[next_x][next_y] == 'P') {
                    return false;
                }
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int t = 0; t < places.size(); t++) {
        vector<string> place = places[t];
        
        bool check = true;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(place[i][j] == 'P') {
                    check = bfs(place, i, j);
                }
                if(!check) break;
            }
            if(!check) break;
        }
        
        answer.push_back(check);
    }
    
    return answer;
}
