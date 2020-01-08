#include <iostream>
#include <string.h>
using namespace std;

int M, N, H;
int tomato[101][101][101];
bool visited[101][101][101];
int q[10000000][4];
int front, rear;
int first[1000001][3];
int fcnt;
int vi[6] = {-1, 1,0,0,0,0};
int vj[6] = {0,0,-1,1,0,0};
int vk[6] = {0,0,0,0,1,-1};

void push(int i, int j, int k, int v)
{
	q[front % 10000000][0] = i;
	q[front % 10000000][1] = j;
	q[front % 10000000][2] = k;
	q[front % 10000000][3] = v;

	front++;
}

void pop()
{
	rear++;
}

void bfs()
{
	for (int i = 0; i < fcnt; i++) {
		int a = first[i][0];
		int b = first[i][1];
		int c = first[i][2];
		push(a, b, c, tomato[a][b][c]);
		visited[a][b][c] = true;
	}

	while (front != rear) {
		int a = q[rear % 10000000][0];
		int b = q[rear % 10000000][1];
		int c = q[rear % 10000000][2];
		int v = q[rear % 10000000][3];
		pop();

		for (int i = 0; i < 6; i++) {
			int ii = a + vi[i];
			int jj = b + vj[i];
			int kk = c + vk[i];

			if (ii >= 0 && ii < H && jj >= 0 && jj < N && kk >= 0 && kk < M) {
				if (!visited[ii][jj][kk] && !tomato[ii][jj][kk]) {
					push(ii, jj, kk, v + 1);
					visited[ii][jj][kk] = true;
					tomato[ii][jj][kk] = v + 1;
				}
			}
		}
	}
}

int main()
{
	fcnt = 0;

	scanf("%d %d %d", &M, &N, &H);
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &tomato[i][j][k]);
				if (tomato[i][j][k] == 1) {
					first[fcnt][0] = i;
					first[fcnt][1] = j;
					first[fcnt][2] = k;
					fcnt++;
				}
			}
		}
	}

	bfs();

	int max = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (tomato[i][j][k] == 0) {
					printf("-1\n");
					return 0;
				}
				if (max < tomato[i][j][k]) {
					max = tomato[i][j][k];
				}
			}
		}
	}

	printf("%d\n", max - 1);

	return 0;
}
