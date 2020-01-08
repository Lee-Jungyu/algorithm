#include <iostream>
#include <string.h>
using namespace std;

int M, N;
int tomato[1001][1001];
bool visited[1001][1001];
int q[1000000][3];
int first[1000000][2];
int fcnt;
int front, rear;
int vi[4] = { -1,0,1,0 };
int vj[4] = { 0,1,0,-1 };


void push(int i, int j, int v)
{
	q[front % 1000000][0] = i;
	q[front % 1000000][1] = j;
	q[front % 1000000][2] = v;
	front++;
}

void pop() 
{
	rear++;
}

void bfs()
{
	for (int i = 0; i < fcnt; i++)
	{
		push(first[i][0], first[i][1], 1);
		visited[first[i][0]][first[i][1]] = true;
	}
	
	while (front != rear) 
	{
		int qi = q[rear%1000000][0];
		int qj = q[rear%1000000][1];
		int qv = q[rear%1000000][2];
		pop();

		for (int a = 0; a < 4; a++)
		{
			int ai = qi + vi[a];
			int aj = qj + vj[a];

			if (ai >= 0 && ai < N && aj >= 0 && aj < M) {
				if (!visited[ai][aj] && !tomato[ai][aj]) {
					tomato[ai][aj] = qv + 1;
					push(ai, aj, tomato[ai][aj]);
					visited[ai][aj] = true;
				}
			}
		}

	}
}

void printmap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			printf("%d ", tomato[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	scanf("%d %d", &M, &N);
	front = rear = 0;
	fcnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1) {
				first[fcnt][0] = i;
				first[fcnt++][1] = j;
			}
		}
	}

	bfs();

	//printmap();
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 0)
			{
				printf("-1\n");
				return 0;
			}
			if (max < tomato[i][j]) {
				max = tomato[i][j];
			}
		}
	}

	printf("%d\n", max - 1);

}
