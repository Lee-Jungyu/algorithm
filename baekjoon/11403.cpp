#include <iostream>
#include <queue>
using namespace std;

int arr[100][100];
int print[100][100];
bool visited[100];
int n;

void bfs();
int main()
{
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			arr[i][j] = 0;
			print[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	bfs();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << print[i][j] << " ";
		cout << endl;
	}
}

void bfs()
{
	queue<int> q;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < n; i++) visited[i] = false;
		q.push(i);
		while (!q.empty())
		{
			int w = q.front();
			for (int j = 0; j < n; j++)
			{
				if (arr[w][j] == 1 && !visited[j])
				{
					q.push(j);
					visited[j] = true;
					print[i][j] = 1;
				}
			}
			q.pop();
		}
	}
}
