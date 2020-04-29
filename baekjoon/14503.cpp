#include <stdio.h>
using namespace std;

int N, M;
int r,c;
int d;
int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, 1, 0, -1};
int map[50][50];
bool visited[50][50] = {{false,},};
int result = 0;

void printmap()
{
        printf("\n");
        for(int i = 0; i < N; i++)
        {
                for(int j = 0; j <M; j++)
                {
                        printf("%d ", map[i][j]);
                }
                printf("\n");
        }
}

bool check_validate(int i, int j)
{
        if(map[i][j] != 1) return true;
        return false;
}

bool check_operation(int i, int j)
{
        int flag = 0;
        for(int i = 0; i < 4; i++) {
                if(visited[r + mx[i]][c + my[i]] == true || map[r + mx[i]][c + my[i]]) flag++;
        }

        if(flag == 4) {
                if(!check_validate(r + mx[(d + 2) % 4], c + my[(d + 2) % 4])) {
                        return false;
                }
        }
        return true;
}

void go_back()
{
        map[r][c] = 4;
        r = r + mx[(d + 2) % 4];
        c = c + my[(d + 2) % 4];
        map[r][c] = 2;
        //visited[r][c] = true;
}

void go_front()
{
        map[r][c] = 4;
        r = r + mx[d];
        c = c + my[d];
        map[r][c] = 2;
        visited[r][c] = true;
}

bool check_back()
{
        int rr = r + mx[(d + 2) % 4];
        int cc = c + my[(d + 2) % 4];

        if(check_validate(rr, cc)) return true;
        return false;
}
bool check_go()
{
        int rr = r + mx[d];
        int cc = c + my[d];

        if(check_validate(rr, cc) && !visited[rr][cc]) return true;
        return false;
}

void turn_left()
{
        d = (d + 3) % 4;
}

void clean()
{
        visited[r][c] = true;
        result++;
}

int main()
{
        scanf("%d %d", &N, &M);
        scanf("%d %d %d", &r, &c, &d);
        for(int i = 0; i < N; i++)
        {
                for(int j = 0; j < M; j++)
                {
                        scanf("%d", &map[i][j]);
                }
        }

        clean();
        int check_cnt = 0;
        while(true) {
                turn_left();
                if(check_go()) {
                        go_front();
                        clean();
                        check_cnt = 0;
                        continue;
                }
                else {
                        check_cnt++;
                        //printf("%d\t%d\t%d\n", check_cnt, r, c);
                        if(check_cnt == 4) {
                                if(check_back()) {
                                        go_back();
                                }
                                if(!check_operation(r, c))
                                {
                                        break;
                                }
                                check_cnt = 0;
                        }
                }
        }

        printf("%d\n", result);
}
