#include <iostream>
#include <string.h>
using namespace std;
int N;
int M;
bool edge[101][101];
bool visited[101];
int result;
int q[1000];
int front, rear;

void push(int n)
{
	q[front%1000] = n;
	front++;
}

int pop()
{
	int v = q[rear % 1000];
	rear++;
	return v;
}

void bfs(int n)
{
	push(n);
	visited[n] = true;
	while (front != rear)
	{
		result++;

		int a = pop();

		for (int i = 1; i <= N; i++)
		{
			if (edge[a][i]) {
				if (!visited[i]) {
					push(i);
					visited[i] = true;
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	scanf("%d", &M);
	memset(edge, 0, sizeof(edge));
	memset(visited, 0, sizeof(visited));
	result = 0;
	front = rear = 0;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		edge[a][b] = true;
		edge[b][a] = true;
	}

	bfs(1);
	printf("%d\n", result - 1);


	return 0;
}
