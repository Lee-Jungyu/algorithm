#include <iostream>
#include <queue>
#define INF 0x3fffffff
using namespace std;

int N;
int map[1001][1001];
int cost[1001];
queue<pair<int, int>> q;

int dijkstra(int s, int d) {
	q.push({ s, 0 });

	while (!q.empty()) {
		int curr = q.front().first;
		int sum = q.front().second;

		q.pop();

		for (int i = 1; i <= N; i++) {
			int c = sum + map[curr][i];
			if (map[curr][i] != INF && cost[i] > c) {
					cost[i] = c;
					q.push({ i, c });
			}
		}
	}

	return cost[d];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 1001; i++) {
		cost[i] = INF;
		for (int j = 0; j < 1001; j++) {
			map[i][j] = INF;
		}
	}

	cin >> N;

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if(map[a][b] > c) map[a][b] = c;
	}

	int s, d;
	cin >> s >> d;

	cout << dijkstra(s, d) << "\n";

}
