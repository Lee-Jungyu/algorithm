#include <iostream>
using namespace std;

char num1[4];
char num2[4];

void myswap(char *s)
{
	char temp;
	
	temp = s[0];
	s[0] = s[2];
	s[2] = temp;
}

char* mymax(char *a, char *b)
{
	myswap(a);
	myswap(b);
	if (atoi(a) > atoi(b)) return a;
	else return b;
}

int main()
{
	scanf("%s %s", num1, num2);

	printf("%s", mymax(num1, num2));

}
