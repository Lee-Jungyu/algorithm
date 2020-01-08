#include <iostream>
#include <string.h>
using namespace std;

int N;
bool map[25][25];
bool visited[25][25];
int q[1000][2];
int front, rear;
int vi[4] = {-1, 0, 1, 0};
int vj[4] = {0, 1, 0, -1};
int cnt[900];

void push(int i, int j)
{
	q[front%1000][0] = i;
	q[front%1000][1] = j;
	front++;
}

void pop()
{
	rear++;
}


void bfs(int i, int j, int n)
{
	push(i, j);
	visited[i][j] = true;
	cnt[n]++;

	while (front != rear)
	{
		int qi, qj;
		qi = q[rear%1000][0];
		qj = q[rear%1000][1];
		
		pop();
		
		for (int a = 0; a < 4; a++)
		{
			if (qi + vi[a] >= 0 && qi + vi[a] < N && qj + vj[a] >= 0 && qj + vj[a] < N)
			{
				if (!visited[qi + vi[a]][qj + vj[a]] && map[qi + vi[a]][qj + vj[a]]) {
					push(qi + vi[a], qj + vj[a]);
					visited[qi + vi[a]][qj + vj[a]] = true;
					cnt[n]++;
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &N);

	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	memset(q, 0, sizeof(q));
	memset(cnt, 0, sizeof(cnt));
	front = rear = 0;
	int c = 0;

	for (int i = 0; i < N; i++)
	{
		char str[26];
		scanf("%s", str);

		for (int j = 0; j < N; j++)
		{
			if (str[j] == '0') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
			}
		}

	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] && !visited[i][j])
			{
				bfs(i, j, c++);
			}
		}
	}


	for (int i = 0; i < c - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < c; j++)
		{
			if (cnt[k] > cnt[j]) 
			{
				k = j;
			}
		}

		int tmp = cnt[k];
		cnt[k] = cnt[i];
		cnt[i] = tmp;
	}


	printf("%d\n", c);
	for (int i = 0; i < c; i++)
	{
		printf("%d\n", cnt[i]);
	}
}
