#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3fffffff
using namespace std;

struct Node {
    int idx;
    int d;
};

struct cmp {
    bool operator()(Node n1, Node n2) {
        return n1.d > n2.d;
    }
};

vector<vector<Node>> edges;
vector<int> dist;
vector<bool> visited;
priority_queue<Node, vector<Node>, cmp> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, s;

    cin >> V >> E >> s;

    dist.resize(V + 1, INF);
    dist[s] = 0;

    visited.resize(V + 1, false);

    edges.resize(V + 1);

    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        Node node;
        node.idx = b;
        node.d = c;

        edges[a].push_back(node);
    }

    Node start_node;
    start_node.idx = s;
    start_node.d = 0;
    pq.push(start_node);

    while(!pq.empty()) {
        int curr_idx = pq.top().idx;
        visited[curr_idx] = true;

        pq.pop();

        for(int i = 0; i < edges[curr_idx].size(); i++) {
            int next_idx = edges[curr_idx][i].idx;
            if(visited[next_idx]) continue;

            if(dist[next_idx] > dist[curr_idx] + edges[curr_idx][i].d) {
                dist[next_idx] = dist[curr_idx] + edges[curr_idx][i].d;
                Node node;
                node.idx = next_idx;
                node.d = dist[next_idx];

                pq.push(node);
            }
        }
    }

    for(int i = 1; i <= V; i++) {
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}
