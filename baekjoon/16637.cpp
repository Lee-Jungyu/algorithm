#include <iostream>
using namespace std;

int N;
int num[10];
char op[10];
int opCnt;
int _max;
bool currArr[10];
bool visited[1000];

void input()
{
	char str[20];
	scanf("%d", &N);
	scanf("%s", str);

	for (int i = 0; i < N; i++)
	{
		if (i % 2) {
			op[i / 2] = str[i];
		}
		else {
			num[i / 2] = str[i] - '0';
		}
	}

	opCnt = N / 2;
}

void output()
{
	printf("%d\n", _max);
}

int bin2dec()
{
	int sum = 0;
	for (int i = 0; i < opCnt; i++) {
		int two = 1;
		for (int j = 0; j < i; j++) {
			two *= 2;
		}
		sum += two * currArr[i];
	}

	return sum;
}

void calculate()
{
	int value = 0;
	int check[10];
	char ocheck[10];
	int chcnt = 0;

	for (int i = 0; i < opCnt + 1; i++)
	{
		check[i] = num[i];
		if (i < opCnt) {
			ocheck[i] = op[i];
		}
	}

	for (int i = 0; i < opCnt; i++)
	{
		if (currArr[i] == 1) {
			if (op[i] == '+')
				check[i] = num[i] + num[i + 1];
			else if (op[i] == '*')
				check[i] = num[i] * num[i + 1];
			else
				check[i] = num[i] - num[i + 1];

			check[i + 1] = 999;
			ocheck[i] = 's';
			chcnt++;
		}
	}

	

	value = check[0];
	for (int i = 0; i < opCnt; i++) {
		if (ocheck[i] == 's') continue;
		else if (ocheck[i] == '+') {
			//cout << " + " << check[i + 1];
			value += check[i + 1];
		}
		else if (ocheck[i] == '*') {
			//cout << " * " << check[i + 1];
			value *= check[i + 1];
		}
		else {
			//cout << " - " << check[i + 1];
			value -= check[i + 1];
		}
	}
	//cout << " = " << value << endl;

	
	if (bin2dec() == 0) _max = value;
	else
		if (_max < value) _max = value;


}


void dfs(int prev, int value)
{
	currArr[prev] = value;

	if (prev == opCnt) {
		if (!visited[bin2dec()])
		{
			calculate();
			visited[bin2dec()] = true;
		}
		return;
	}

	if (currArr[prev] == 1) {
		dfs(prev + 1, 0);
	}
	else {
		dfs(prev + 1, 0);
		dfs(prev + 1, 1);
	}
}

void solution()
{
	calculate();

	for (int i = 0; i < opCnt; i++)
	{
		dfs(i, 1);
		currArr[i] = 0;
	}
}

int main()
{
	input();
	solution();
	output();
	
}
