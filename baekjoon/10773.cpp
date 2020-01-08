#include <iostream>
using namespace std;

int K;
int s[100001];
int top = -1;
unsigned long long int sum = 0;

void push(int n)
{
	s[++top] = n;
}

void pop()
{
	top--;
}

int main()
{
	scanf("%d", &K);

	int n;
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &n);

		if (n) {
			push(n);
		}
		else {
			pop();
		}
	}

	for (int i = 0; i <= top; i++)
	{
		sum += s[i];
	}

	printf("%d\n", sum);
}
