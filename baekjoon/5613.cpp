#include <iostream>
using namespace std;

int main()
{
	int n, r;
	char c = 'a';

	scanf(" %d", &r);

	while (c != '=')
	{
		scanf(" %c", &c);
		if (c == '=') break;
		scanf(" %d", &n);

		if (c == '+') r += n;
		else if (c == '-') r -= n;
		else if (c == '*') r *= n;
		else if (c == '/') r /= n;
	}
	
	printf("%d\n", r);
}
