#include <iostream>
using namespace std;

int N; //class cnt
int A[1000001]; //student cnt for class
int B; //student cnt the supervisor can supervise
int C; //student cnt the sub supervisor can supervise
int Ccnt[1000001]; //sub supervisor cnt for class
long long int totalSupervisorCnt = 0; //total supervisor cnt

void input()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}
	scanf("%d %d", &B, &C);
}

void solve()
{
	totalSupervisorCnt += N;
	for (int i = 1; i <= N; i++)
	{
		A[i] -= B;
	}

	for (int i = 1; i <= N; i++)
	{
		if (A[i] <= 0)
			Ccnt[i] = 0;
		else if (A[i] % C == 0)
			Ccnt[i] = A[i] / C;
		else
			Ccnt[i] = A[i] / C + 1;
	}

	for (int i = 1; i <= N; i++)
	{
		totalSupervisorCnt += Ccnt[i];
	}
}

void output()
{
	printf("%lld\n", totalSupervisorCnt);
}

int main()
{
	input();
	solve();
	output();
}
