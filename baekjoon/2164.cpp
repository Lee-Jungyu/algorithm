#include <iostream>
using namespace std;

int q[1000000];
int N;
int cnt;
int front, rear;

void push(int n)
{
	q[front++] = n;
}

void pop()
{
	rear++;
}

int main()
{
	scanf("%d", &N);
	cnt = N;
	front = rear = 0;

	for (int i = 1; i <= N; i++)
	{
		push(i);
	}

	while (true)
	{
		if (cnt == 1) break;
		pop();
		cnt--;

		if (cnt == 1) break;
		push(q[rear % 1000000]);
		pop();
	}

	printf("%d\n", q[front - 1 % 1000000]);

}
