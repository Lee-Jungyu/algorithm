#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int alpha[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };

	char word[16];

	scanf("%s", word);

	int length = strlen(word);
	int sum = 0;

	for (int i = 0; i < length; i++)
		sum += alpha[word[i] - 'A'];

	printf("%d\n", sum);

	return 0;
}
