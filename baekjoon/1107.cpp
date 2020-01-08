#include <iostream>
using namespace std;

bool broken[10];
int N, M;
int curr = 100;
int Nsplit[6];
int nLen;

void input()
{
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		int n;
		scanf("%d", &n);
		broken[n] = true;
	}
}

int length(int n)
{
	int len = 0;

	if (n == 0) {
		if (broken[0]) return 0;
		else return 1;
	}

	while (n) {
		if (broken[n % 10]) return 0;
		len++;
		n /= 10;
	}

	return len;
}

int findSmall(int num, int level, int sum)
{
	int n = 0;

	for (int i = 0; i < level; i++)
	{
		n *= 10;
		n += Nsplit[i];
	}

	sum *= 10;
	sum += num;
	
	if (level == nLen) {
		return sum;
	}

	for (int i = 9; i > -1; i--)
	{
		int c = sum * 10 + i;
		if (length(c) && c <= n * 10 + Nsplit[level]) {
			int a = findSmall(i, level + 1, sum);
			if (a != -1) {
				return a;
			}
		}
	}
	
	return -1;
}

int findBig(int num, int level, int sum)
{
	int n = 0;

	for (int i = 0; i < level; i++)
	{
		n *= 10;
		n += Nsplit[i];
	}

	sum *= 10;
	sum += num;

	if (level == nLen) {
		return sum;
	}

	int a;
	for (int i = 0; i < 10; i++)
	{
		int c = sum * 10 + i;
		if (length(c) && c >= n * 10 + Nsplit[level]) {
			int a = findBig(i, level + 1, sum);
			if (a != -1) {
				return a;
			}
		}
	}

	return -1;
}

int solve()
{
	int result;

	if (N - 100 > 0) {
		result = N - 100;
	}
	else {
		result = 100 - N;
	}

	int num = N;
	nLen = 0; //자릿수
	while (num) {
		Nsplit[nLen++] = num % 10;
		num /= 10;
	}

	if (N == 0) {
		nLen = 1;
	}

	for (int i = 0; i < nLen / 2; i++) {
		int tmp = Nsplit[i];
		Nsplit[i] = Nsplit[nLen - i - 1];
		Nsplit[nLen - i - 1] = tmp;
	}

	//N입력 시 고장난 버튼 없을 경우
	int check = length(N);
	if (check) {
		if (result < check) {
			return result;
		}
		else {
			return check;
		}
	}

	//N입력 시 고장난 버튼 있을 경우
	int small = -1;
	int big = -1;
	if (!broken[Nsplit[0]]) {
		small = findSmall(Nsplit[0], 1, 0);
		big = findBig(Nsplit[0], 1, 0);
	}
	if (small == -1) {
		for (int i = Nsplit[0] - 1; i > -1; i--) {
			if (i == 0 && nLen != 1) {
				small = findSmall(i, 1, 0);
				break;
			}
			if (!broken[i]) {
				small = findSmall(i, 1, 0);
				break;
			}
		}
	}
	if (big == -1) {
		big = findBig(1, 0, 0);
		for (int i = Nsplit[0] + 1; i < 10; i++) {
			if (!broken[i]) {
				int b = findBig(i, 1, 0);
				if (big == -1) big = b;
				if (big > b) big = b;
				break;
			}
		}
	}

	if (big != -1 || small != -1) {
		if (small == -1) {
			if (big - N + length(big) < result) {
				result = big - N + length(big);
			}
		}
		else if (big == -1) {
			if (N - small + length(small) < result) {
				result = N - small + length(small);
			}
		}
		else {
			if (big - N < N - small) {
				if (big - N + length(big) < result) {
					result = big - N + length(big);
				}
			}
			else {
				if (N - small + length(small) < result) {
					result = N - small + length(small);
				}
			}
		}
	}

	return result;
}

void output()
{
	printf("%d\n", solve());
}

int main()
{
	input();
	output();
}
