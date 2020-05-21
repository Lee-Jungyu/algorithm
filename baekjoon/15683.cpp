#include <stdio.h>
using namespace std;

bool visited[8][8] = {{false,},};
int map[8][8];
int N, M;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int result = 1000;
int cctv_cnt = 0;

void dfs(int x, int y, int m[][8], int cnt)
{
    int tmp_map[8][8];
    
    int type = m[x][y];

    for(int d = 0; d < 4; d++) 
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                tmp_map[i][j] = m[i][j];
            }
        }

        int mx = x;
        int my = y;
        switch(type) {
        case 1:
            mx = x;
            my = y;

            while(mx >= 0 && mx < N && my >= 0 && my < M) {
                if(tmp_map[mx][my] == 6) break;
                if(tmp_map[mx][my] != 0) {
                    mx = mx + dx[d];
                    my = my + dy[d];
                    continue;
                }

                tmp_map[mx][my] = 9;

                mx = mx + dx[d];
                my = my + dy[d];
            }
            break;
            
        case 2:
            mx = x;
            my = y;
            while(mx >= 0 && mx < N && my >= 0 && my < M) {
                if(tmp_map[mx][my] == 6) break;
                if(tmp_map[mx][my] != 0) {
                    mx = mx + dx[d];
                    my = my + dy[d];
                    continue;
                } 

                tmp_map[mx][my] = 9;

                mx = mx + dx[d];
                my = my + dy[d];
            }

            mx = x;
            my = y;

            while(mx >= 0 && mx < N && my >= 0 && my < M) {
                if(tmp_map[mx][my] == 6) break;
                if(tmp_map[mx][my] != 0) {
                    mx = mx + dx[(d + 2) % 4];
                    my = my + dy[(d + 2) % 4];
                    continue;
                }

                tmp_map[mx][my] = 9;

                mx = mx + dx[(d + 2) % 4];
                my = my + dy[(d + 2) % 4];
            }

            break;
            
        case 3:
            mx = x;
            my = y;
            while(mx >= 0 && mx < N && my >= 0 && my < M) {
                if(tmp_map[mx][my] == 6) break;
                if(tmp_map[mx][my] != 0) {
                    mx = mx + dx[d];
                    my = my + dy[d];
                    continue;
                }

                tmp_map[mx][my] = 9;

                mx = mx + dx[d];
                my = my + dy[d];
            }

            mx = x;
            my = y;

            while(mx >= 0 && mx < N && my >= 0 && my < M) {
                if(tmp_map[mx][my] == 6) break;
                if(tmp_map[mx][my] != 0) {
                    mx = mx + dx[(d + 1) % 4];
                    my = my + dy[(d + 1) % 4];
                    continue;
                }

                tmp_map[mx][my] = 9;

                mx = mx + dx[(d + 1) % 4];
                my = my + dy[(d + 1) % 4];
            }

            break;
            
        case 4:
            mx = x;
            my = y;
            while(mx >= 0 && mx < N && my >= 0 && my < M) {
                if(tmp_map[mx][my] == 6) break;
                if(tmp_map[mx][my] != 0) {
                    mx = mx + dx[(d + 1) % 4];
                    my = my + dy[(d + 1) % 4];
                    continue;
                }

                tmp_map[mx][my] = 9;

                mx = mx + dx[(d + 1) % 4];
                my = my + dy[(d + 1) % 4];
            }

            mx = x;
            my = y;

            while(mx >= 0 && mx < N && my >= 0 && my < M) {
                if(tmp_map[mx][my] == 6) break;
                if(tmp_map[mx][my] != 0) {        
                    mx = mx + dx[(d + 2) % 4];
                    my = my + dy[(d + 2) % 4];
                    continue;
                }

                tmp_map[mx][my] = 9;

                mx = mx + dx[(d + 2) % 4];
                my = my + dy[(d + 2) % 4];
            }

            mx = x;
            my = y;

            while(mx >= 0 && mx < N && my >= 0 && my < M) {
                if(tmp_map[mx][my] == 6) break;
                if(tmp_map[mx][my] != 0) {
                    mx = mx + dx[(d + 3) % 4];
                    my = my + dy[(d + 3) % 4];
                    continue;
                }

                tmp_map[mx][my] = 9;

                mx = mx + dx[(d + 3) % 4];
                my = my + dy[(d + 3) % 4];
            }

            break;
        }

        if(cctv_cnt == cnt) {
            int value = 0;
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < M; j++)
                {
                    if(tmp_map[i][j] == 0) value++;
                }
            }

            if(value < result) {
                result = value;
            }
        }

        if(cctv_cnt > cnt)
        {
            for(int i = x; i < N; i++)
            {
                for(int j = 0; j < M; j++)
                {
                    if(map[i][j] >= 1 && map[i][j] <= 4 && !visited[i][j]) {
                        visited[i][j] = true;
                        dfs(i, j, tmp_map, cnt + 1);
                        visited[i][j] = false;
                    }
                }
            }
        }
    }

}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &map[i][j]);
            if(map[i][j] >= 1 && map[i][j] <= 4) cctv_cnt++;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(map[i][j] == 5) {
                visited[i][j] = true;
                int mx = i;
                int my = j;
                
                while(mx >= 0 && mx < N && my >= 0 && my < M) {
                    if(map[mx][my] == 6) break;
                    if(map[mx][my] != 0) {
                        mx = mx + dx[0];
                        my = my + dy[0];
                        continue;
                    }

                    map[mx][my] = 9;

                    mx = mx + dx[0];
                    my = my + dy[0];
                }

                mx = i;
                my = j;

                while(mx >= 0 && mx < N && my >= 0 && my < M) {
                    if(map[mx][my] == 6) break;
                    if(map[mx][my] != 0) {
                        mx = mx + dx[1];
                        my = my + dy[1];
                        continue;
                    }

                    map[mx][my] = 9;

                    mx = mx + dx[1];
                    my = my + dy[1];
                }

                mx = i;
                my = j;

                while(mx >= 0 && mx < N && my >= 0 && my < M) {
                    if(map[mx][my] == 6) break;
                    if(map[mx][my] != 0) {
                        mx = mx + dx[2];
                        my = my + dy[2];
                        continue;
                    }

                    map[mx][my] = 9;

                    mx = mx + dx[2];
                    my = my + dy[2];
                }

                mx = i;
                my = j;

                while(mx >= 0 && mx < N && my >= 0 && my < M) {
                    if(map[mx][my] == 6) break;
                    if(map[mx][my] != 0) {
                        mx = mx + dx[3];
                        my = my + dy[3];
                        continue;
                    }
                    map[mx][my] = 9;

                    mx = mx + dx[3];
                    my = my + dy[3];
                }
            }
        }
    }

    int value = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(map[i][j] == 0) value++;
        }
    }
    result = value;

    bool flag = false;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(map[i][j] >= 1 && map[i][j] <= 4) {
                visited[i][j] = true;
                dfs(i, j, map, 1);
                flag = true;
                break;
            }
        }
        if (flag) break;
    }


    printf("%d\n", result);

}
