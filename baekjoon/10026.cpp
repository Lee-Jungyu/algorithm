#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
char map[101][101];

int bfs() {
	int a = 0;
	bool visited[101][101] = { {false,}, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			a++;
			char color = map[i][j];
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			visited[i][j] = true;

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int d = 0; d < 4; d++) {
					int xx = x + dx[d];
					int yy = y + dy[d];

					if (xx >= 0 && xx < n && y >= 0 && yy < n) {
						if (map[xx][yy] == color && !visited[xx][yy]) {
							q.push(make_pair(xx, yy));
							visited[xx][yy] = true;
						}
					}
				}
			}
 		}
	}

	return a;
}

int cwbfs() {
	int b = 0;
	bool visited[101][101] = { {false,}, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;

			b++;
			char color = map[i][j];
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			visited[i][j] = true;

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int d = 0; d < 4; d++) {
					int xx = x + dx[d];
					int yy = y + dy[d];

					if (xx >= 0 && xx < n && y >= 0 && yy < n) {
						if (!visited[xx][yy] && (map[xx][yy] == color || (map[xx][yy] == 'R' && color == 'G') || (map[xx][yy] == 'G' && color == 'R'))) {
							q.push(make_pair(xx, yy));
							visited[xx][yy] = true;
						}
					}
				}
			}
		}
	}

	return b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j];
		}
	}

	int a = bfs();
	int b = cwbfs();

	cout << a << " " << b << endl;
}
