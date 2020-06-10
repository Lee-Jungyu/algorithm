#include <stdio.h>
using namespace std;

int N, M, H;
bool ladder[32][12] = {{false,},};
bool visited[32][12] = {{false,},};
int min_value = 99;

int game_start(int idx) {
    int x_pose = idx;
    int y_pose = 1;

    while(y_pose <= H) {
        if(ladder[y_pose][x_pose] && !visited[y_pose][x_pose]) {
            visited[y_pose][x_pose] = true;
            x_pose = x_pose + 1;
        }
        if(ladder[y_pose][x_pose - 1] && !visited[y_pose][x_pose - 1]) {
            visited[y_pose][x_pose - 1] = true;
            x_pose = x_pose - 1;
        }
        visited[y_pose][x_pose] = visited[y_pose][x_pose - 1] = false;
        y_pose ++;
    }

    return x_pose;
}

void dfs(int cnt, int r, int c)
{
    int idx;
    for(idx = 1; idx <= N; idx++) {
        int result = game_start(idx);
        if(result != idx) break;
    }

    if(idx == N + 1) {
        if(min_value > cnt) min_value = cnt;
        return;
    }

    if(cnt == 3) {
        return;
    }

    for(int i = r; i <= H; i++) {
        for(int j = 1; j < N; j++) {
            if(i == r && j <= c + 1) continue;
            
            if(!ladder[i][j - 1] && !ladder[i][j] && !ladder[i][j + 1]) {
                ladder[i][j] = true;
                dfs(cnt + 1, i, j);
                ladder[i][j] = false;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &H);
    for(int i = 0; i < M; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        ladder[r][c] = true;
    }

    int idx;
    for(idx = 1; idx <= N; idx++) {
        int result = game_start(idx);
        if(result != idx) break;
    }

    if(idx == N + 1) {
        printf("0\n");
        return 0;
    }

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j < N; j++) {
            if(!ladder[i][j - 1] && !ladder[i][j] && !ladder[i][j + 1]) {
                ladder[i][j] = true;
                dfs(1, i, j);
                ladder[i][j] = false;
            }
        }
    }

    min_value = min_value == 99 ? -1 : min_value;
    printf("%d\n", min_value);
}
