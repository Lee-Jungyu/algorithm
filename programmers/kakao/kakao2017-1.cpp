#include <vector>

using namespace std;

int N, M;
int front, rear, idxCnt;
int q[20000][3];
bool visited[100][100];
int idx[10000];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void push(int x, int y, int v) {
	q[front % 20000][0] = x;
	q[front % 20000][1] = y;
	q[front % 20000][2] = v;
	front++;
}

void pop()
{
	rear++;
}

bool checkBorder(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < M)
	{
		return false;
	}
	else {
		return true;
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

	int number_of_area = 0;
	int max_size_of_one_area = 0;

	front = rear = 0;
	idxCnt = 0;
	N = picture.size();
	M = picture[0].size();

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = false;

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			if (!visited[x][y] && picture[x][y] != 0)
			{
				int v = picture[x][y];
				int sum = 0;

				push(x, y, v);
				visited[x][y] = true;

				while (front != rear)
				{
					int xx = q[rear % 20000][0];
					int yy = q[rear % 20000][1];
					int vv = q[rear % 20000][2];
					pop();
					sum++;

					for (int i = 0; i < 4; i++)
					{
						int dxx = xx + dx[i];
						int dyy = yy + dy[i];

						if (!checkBorder(dxx, dyy))
						{
							if (!visited[dxx][dyy] && vv == picture[dxx][dyy]) {
								push(dxx, dyy, vv);
								visited[dxx][dyy] = true;
							}
						}
					}
				}
				idx[idxCnt++] = sum;
			}
		}
	}

	number_of_area = idxCnt;
	max_size_of_one_area = idx[0];
	for (int i = 0; i < idxCnt; i++)
	{
		if (idx[i] > max_size_of_one_area) {
			max_size_of_one_area = idx[i];
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

