#include <iostream>
using namespace std;

int map[11][11];
int cnt[6];
int minV = -1;
int value = 99999;

void input() {

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

bool checkRest()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1) {
				return false;
			}
		}
	}

	return true;
}

void search(int y, int x, int num) {
	if (x + num - 1 >= 10 || y + num - 1 >= 10) {
		return;
	}

	//num칸 크기의 색종이가 5장 사용되었으면 return
	if (cnt[num] >= 5) {
		return;
	}

	//num칸 크기의 색종이가 겹쳐질 공간이 있는지 check
	for (int i = y; i < y + num; i++) {
		for (int j = x; j < x + num; j++) {
			if (map[i][j] != 1) {
				return;
			}
		}
	}

	//num칸 만큼 색종이를 겹침
	for (int i = y; i < y + num; i++) {
		for (int j = x; j < x + num; j++) {
			map[i][j] = num + 1;
		}
	}

	cnt[num]++;

	bool flag = false;

	for (int i = y; i < 10; i++) {
		if (flag) break;

		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1) {
				flag = true;
				for (int k = 5; k > 0; k--) {
					search(i, j, k);
				}
				break;
			}

			if (i == 9 && j == 9) {
				if (checkRest()) {
					int value = 0;
					for (int k = 5; k > 0; k--) {
						value += cnt[k];
					}
					if (minV == -1) { minV = value; }
					else if (minV > value) { minV = value; }
				}
			}
		}
	}

	//num칸 만큼 색종이를 빼줌
	for (int i = y; i < y + num; i++) {
		for (int j = x; j < x + num; j++) {
			map[i][j] = 1;
		}
	}


	cnt[num]--;
}

void solve() {
	bool flag = false;
	for (int i = 0; i < 10; i++) {
		if (flag) {
			break;
		}
		for (int j = 0; j < 10; j++) {
			if (map[i][j]) {
				flag = true;
				
				for (int k = 5; k > 0; k--) {
					search(i, j, k);
				}

				break;
			}
		}
	}

	if (!flag) {
		minV = 0;
	}
}

void output() {
	printf("%d\n", minV);
}

int main()
{
	input();
	solve();
	output();
}

