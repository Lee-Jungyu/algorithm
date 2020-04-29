#include <stdio.h>
using namespace std;

int N, M;
int map[9][9];
int tmpmap[9][9];
bool visited[9][9] = {{false,},};
bool visited2[9][9] = {{false,},};
int q[100000][2];
int qfront, qrear;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int _max = 0;

void printmap()
{
        printf("\n");
        for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++) {
                        printf("%d ", tmpmap[i][j]);
                }
                printf("\n");
        }
}

bool checkMap(int i, int j)
{
        if(i >= 0 && i < N && j >= 0 && j < M)
        {
                return true;
        }
        return false;
}

bool checkValidate(int i, int j)
{
        if(map[i][j] == 0) return true;
        return false;
}

void getMax()
{
        int sum = 0;
        for(int i = 0; i < N; i++)
        {
                for(int j = 0; j < M; j++)
                {
                        if(tmpmap[i][j] == 0)
                                sum++;
                }
        }

        _max = _max > sum ? _max : sum;
}

void q_push(int i, int j)
{
        q[qrear][0] = i;
        q[qrear][1] = j;
        qrear++;
        qrear = qrear % 100000;
}

void q_pop()
{
        qfront++;
        qfront = qfront % 100000;
}

void bfs(int i, int j)
{
        q_push(i, j);

        while(qfront != qrear)
        {
                int qi = q[qfront][0];
                int qj = q[qfront][1];

                tmpmap[qi][qj] = 2;
                visited[qi][qj] = true;

                q_pop();

                for(int t = 0; t < 4; t++)
                {
                        int qii = qi + dx[t];
                        int qjj = qj + dy[t];
                        if(checkMap(qii, qjj))
                        {
                                if(map[qii][qjj] == 0 && !visited[qii][qjj])
                                        q_push(qii, qjj);
                        }
                }
        }
}

void initTmpMap()
{
        for(int i = 0; i < N; i++)
        {
                for(int j = 0; j < M; j++)
                {
                        visited[i][j] = false;
                        tmpmap[i][j] = map[i][j];
                }
        }
}

void dfs(int cnt, int i, int j)
{
        map[i][j] = 1;
        visited2[i][j] = true;
        if(cnt == 3) {
                //bfs
                initTmpMap();
                for(int i = 0; i < N; i++)
                {
                        for(int j = 0; j < M; j++)
                        {
                                if(map[i][j] == 2)
                                {
                                        bfs(i, j);
                                }
                        }
                }

                getMax();

                map[i][j] = 0;
                visited2[i][j] = false;
                return;
        }

        for(int _i = i; _i < N; _i++)
        {
                for(int _j = 0; _j < M; _j++)
                {
                        if(checkValidate(_i, _j) && !visited2[_i][_j]) {
                                dfs(cnt + 1, _i, _j);
                        }
                }
        }
        visited2[i][j] = false;
        map[i][j] = 0;
}

int main()
{
        qfront = qrear = 0;
        scanf("%d %d", &N, &M);

        for(int i = 0; i < N; i++)
        {
                for(int j = 0; j < M; j++)
                {
                        scanf("%d", &map[i][j]);
                }
        }

        for(int i = 0; i < N; i++)
        {
                for(int j = 0; j < M; j++)
                {
                        if(checkValidate(i, j)) {
                                dfs(1, i, j);
                        }
                }
        }


        printf("%d\n", _max);

        return 0;
}
