#include <iostream>
using namespace std;

char input[100];
int flag[26];

int main()
{
	for (int i = 0; i < 26; i++)
		flag[i] = -1;
	scanf("%s", &input);
	int i;
	for (i = 0; i < sizeof(input); i++) {
		if (input[i] >= 97 && input[i] <= 123) {
			if (flag[input[i] - 97] == -1) {
				flag[input[i] - 97] = i;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", flag[i]);
	}
	printf("\n");
	return 0;
}
