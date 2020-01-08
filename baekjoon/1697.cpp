#include <iostream>
using namespace std;

int N, K;
int C;
int t;
int q[1000000];
int p[1000000];
int front, rear;
bool visited[100001];

void find()
{
	int v = N;
	p[front%1000000] = t;
	q[(front+1)%1000000] = N;
	front++;
	while (true)
	{
		t = p[rear%1000000];
		v = q[(rear + 1)%1000000];
		rear++;
		if (v - 1 > -1)
		{
			if (!visited[v - 1]) 
			{
				p[front % 1000000] = t + 1;
				q[(front+1) % 1000000] = v - 1;
				visited[v - 1] = true;
				front++;
			}
		}
		if (v + 1 < 100001)
		{
			if (!visited[v + 1]) 
			{
				p[front % 1000000] = t + 1;
				q[(front+1) % 1000000] = v + 1;
				visited[v + 1] = true;
				front++;
			}
		}
		if (v * 2 < 100001)
		{
			if (!visited[v * 2]) 
			{
				p[front % 1000000] = t + 1;
				q[(front+1) % 1000000] = v * 2;
				visited[v * 2] = true;
				front++;
			}
		}
		if (v == K) 
		{
			break;
		}

	}
}

int main()
{
	front = 0, rear = 0, t = 0;
	cin >> N >> K;
	find();
	
	cout << t;
	return 0;
}
