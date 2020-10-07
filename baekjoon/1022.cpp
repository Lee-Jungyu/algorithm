#include <iostream>
#include <math.h>

using namespace std;

int r1, r2, c1, c2;
int map[50][5];

int get_length(int n) {
	int length = 0;
	while (n) {
		length++;
		n /= 10;
	}

	return length;
}

void make_square(int r_idx, int c_idx, int value, int size, int cnt) {
	if (cnt == 0) return;
	for (int i = 0; i < size; i++) {
		//map[r_idx--][c_idx] = value++;
		if (r_idx >= r1 && r_idx <= r2 && c_idx >= c1 && c_idx <= c2) {
			map[r_idx - r1][c_idx - c1] = value;
		}
		r_idx--;
		value++;
	}
	r_idx++;
	c_idx--;
	for (int i = 0; i < size; i++) {
		if (r_idx >= r1 && r_idx <= r2 && c_idx >= c1 && c_idx <= c2) {
			map[r_idx - r1][c_idx - c1] = value;
		}
		c_idx--;
		value++;
	}
	c_idx++;
	r_idx++;
	for (int i = 0; i < size; i++) {
		if (r_idx >= r1 && r_idx <= r2 && c_idx >= c1 && c_idx <= c2) {
			map[r_idx - r1][c_idx - c1] = value;
		}
		r_idx++;
		value++;
	}
	r_idx--;
	c_idx++;
	for (int i = 0; i <= size; i++) {
		if (r_idx >= r1 && r_idx <= r2 && c_idx >= c1 && c_idx <= c2) {
			map[r_idx - r1][c_idx - c1] = value;
		}
		c_idx++;
		value++;
	}
	c_idx--;
	value--;
	make_square(r_idx, c_idx, value, size + 2, cnt - 1);
}

void print_map() {
	int max = 0;
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			if (max < map[i][j]) max = map[i][j];
		}
	}

	int leng = get_length(max);
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			for (int k = 0; k < leng - get_length(map[i][j]); k++)
				printf(" ");
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	int r_idx = 0;
	int c_idx = 0;
	int value = 1;
 	if (r_idx >= r1 && r_idx <= r2 && c_idx >= c1 && c_idx <= c2) {
		map[r_idx - r1][c_idx - c1] = value;
	}
	value++;
	int max_r = abs(r1) < abs(r2) ? abs(r2) : abs(r1);
	int max_c = abs(c1) < abs(c2) ? abs(c2) : abs(c1);
	int cnt = max_r < max_c ? max_c : max_r;

	make_square(r_idx, c_idx + 1, value, 2, cnt);
	print_map();
}
