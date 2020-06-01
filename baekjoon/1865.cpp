#include <stdio.h>
#include <vector>
using namespace std;
#define INF 1000000000

int main()
{
    int TC;
    scanf("%d", &TC);
    
    while(TC--)
    {
        int N, M, W;
        scanf("%d %d %d", &N, &M, &W);

        vector<vector<pair<int, int> > > edge(N + 1);
        vector<int> dist(N + 1, INF);
        dist[1] = 0;

        for(int i = 0; i < M; i++)
        {
            int S, E, T;
            scanf("%d %d %d", &S, &E, &T);
            edge[S].push_back({E, T});
            edge[E].push_back({S, T});
        }

        for(int i = 0; i < W; i++)
        {
            int S, E, T;
            scanf("%d %d %d", &S, &E, &T);
            edge[S].push_back({E, -T});
        }

        bool minus_cycle = false;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                int edge_size = edge[j].size();
                for(int k = 0; k < edge_size; k++) {
                    int from = j;
                    int to = edge[j][k].first;
                    int weight = edge[j][k].second;

                    if(dist[from] + weight < dist[to]) {
                        dist[to] = dist[from] + weight;
                        if(i == N) minus_cycle = true;
                    }
                }
            }
        }

        if(minus_cycle) printf("YES\n");
        else printf("NO\n");
    }
}

//벨만포드 알고리즘
