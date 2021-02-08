#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int startX, startY;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 9) {
                startX = i;
                startY = j;
            } 
        }
    }

    int sum = 0;
    int shark = 2;
    int eat_cnt = 0;
    
    while(true) {
        queue<vector<int>> q;
        bool visited[21][21] = {{false, }, };
        q.push({startX, startY, 0});
        visited[startX][startY] = true;

        map[startX][startY] = 0;

        int dist = 999;
        while(!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int tmp_dist = q.front()[2];

            if(map[x][y] != 0 && map[x][y] < shark) {
                if(tmp_dist < dist) {
                    dist = tmp_dist;
                    startX = x;
                    startY = y;
                }
                else if(tmp_dist == dist) {
                    if(x < startX || (x == startX && y < startY)) {
                        startX = x;
                        startY = y;
                    } 
                }
            }
            q.pop();

            for(int i = 0; i < 4; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];

                if(tx >= 0 && tx < N && ty >= 0 && ty < N) {
                    if(!visited[tx][ty] && map[tx][ty] <= shark) {
                        q.push({tx, ty, tmp_dist + 1});
                        visited[tx][ty] = true;
                    }
                }
            }
        }

        map[startX][startY] = 9;

        if(dist == 999) {
            break;
        }
        sum += dist;
        eat_cnt++;

        if(shark == eat_cnt) {
            eat_cnt = 0;
            shark++;
        }
    }

    cout << sum << '\n';

    return 0;
}
