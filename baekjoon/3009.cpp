#include <iostream>
using namespace std;


int main()
{
	int check[1001][2] = { 0, };
	int n, m; 
	int xx = 0, yy = 0;

	for (int i = 0; i < 3; i++) 
	{
		scanf("%d %d", &n, &m);
		check[n][0]++;
		check[m][1]++;
	}

	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 2; j++) {
			if (check[i][j] == 1) {
				if (j == 0) {
					xx = i;
				}
				if (j == 1) {
					yy = i;
				}
			}
		}
	}

	printf("%d %d\n", xx, yy);
}
