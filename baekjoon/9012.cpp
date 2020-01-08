#include <iostream>
using namespace std;

int main()
{
	int T;
	char str[51];
	
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		bool isTrue = true;
		int lr = 0;

		scanf("%s", str);

		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '(') lr++;
			if (str[i] == ')') lr--;


			if (lr < 0) {
				isTrue = false;
				break;
			}
		}

		if (lr != 0) isTrue = false;

		if (isTrue) printf("YES\n");
		else printf("NO\n");
	}

}
