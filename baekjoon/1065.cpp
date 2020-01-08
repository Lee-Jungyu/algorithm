#include <iostream>
using namespace std;

int hansu(int input)
{
	if (input < 100) return input;
	
	int a, b, c;
	

	int total = 99;
	
	for (int i = 100; i <= input; i++)
	{
		a = i / 100;
		b = i % 100 / 10;
		c = i % 10;
		if (a - b == b - c)
			total += 1;
	}
	return total;
}


int main()
{
	int input;
	scanf("%d", &input);

	printf("%d", hansu(input));

	return 0;
}
