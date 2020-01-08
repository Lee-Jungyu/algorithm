#include <iostream>
#include <string>
using namespace std;

char OX[80];

int main()
{
	int tc;
	int sum;
	string input;
	scanf("%d", &tc);

	while (tc--)
	{
		sum = 0;
		cin >> input;
		for (int i = 0; i < input.length(); i++)
		{
			OX[i] = input[i];
		}
		int cnt = 0;
		for (int i = 0; i < input.length(); i++)
		{
			cnt++;
			if (OX[i] == 'X') {
				cnt = 0;
			}
			else {
				sum += cnt;
			}
		}
		printf("%d\n", sum);
	}
}
