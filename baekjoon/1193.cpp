#include <iostream>
using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	int cnt = 0;
	int numerator; //분자
	int denominator; //분모
	for (int i = 1;;i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (cnt == num) break;
			if (i % 2 == 0) //짝수번째 층 (분자 작아지고 분모 커짐)
			{
				numerator = j + 1;
				denominator = i - j;
			}
			else //홀수번째 층 (분자 커지고 분모 작아짐)
			{
				numerator = i - j;
				denominator = j + 1;
			}
			cnt++;
		}
		if (cnt == num) break;
	}

	printf("%d/%d\n", numerator, denominator);
	return 0;
}
