#include <iostream>
using namespace std;
int min(int, int);

int X;
int df[1000001] = { 0, };

int main()
{
	scanf("%d", &X);
	df[1] = 0;
	if (X == 1)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 2; i <= X; i++)
	{
		df[i] = df[i - 1] + 1;
		if (!(i % 2)) df[i] = min(df[i], df[i / 2] + 1);
		if (!(i % 3)) df[i] = min(df[i], df[i / 3] + 1);
	}

	cout << df[X] << endl;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
