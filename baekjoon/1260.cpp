#include <iostream>
using namespace std;

int N, M, V;
int q[10000];
int front, rear, top;
int s[10000];
int arr[1001][1001] = { 0, };
bool visited[1001] = { false, };


void q_push(int v)
{
	q[front++] = v;
}

int q_pop()
{
	if (rear == front)
		return -1;
	return q[rear++];
}

void BFS()
{
	q_push(V);
	visited[V] = true;
	while (front != rear)
	{
		int w = q_pop();
		cout << w << " ";
		for (int i = 1; i <= N; i++)
		{
			if (arr[i][w] == 1 && !visited[i])
			{
				q_push(i);
				visited[i] = true;
			}
		}
	}
	cout << endl;
}

void s_push(int v)
{
	s[++top] = v;
}

int s_pop()
{
	return s[top--];
}

void DFS(int v)
{
	cout << v << " ";
	visited[v] = true;
	for (int i = 1; i <= N; i++)
	{
		if (arr[i][v] == 1 && !visited[i])
		{
			DFS(i);
		}
	}
}

int main()
{
	front = 0; rear = 0; top = -1;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;

		arr[v1][v2] = 1;
		arr[v2][v1] = 1;
	}
	DFS(V);
	for (int i = 1; i <= N; i++) visited[i] = false;
	cout << endl;
	BFS();
    return 0;
}
