#include <iostream>
using namespace std;
int person[50][2];
int order[50] = { 0, };

int main()
{
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &person[i][0], &person[i][1]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (person[i][0] > person[j][0] && person[i][1] > person[j][1])
				order[j]++;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << order[i] + 1 << " ";
	}
}
