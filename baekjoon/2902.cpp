#include <iostream>
using namespace std;

int main()
{
	char str[101];
	char result[101];
	int rCnt = 0;
	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') {
			result[rCnt++] = str[i];
		}
	}
	result[rCnt] = '\0';

	printf("%s\n", result);
}
