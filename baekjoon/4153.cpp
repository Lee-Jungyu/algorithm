#include <iostream>
using namespace std;


int main()
{
	int x, y, z;

	while(1) {
		scanf("%d %d %d", &x, &y, &z);

		if (x * y * z == 0) return 0;

		if (x * x + y * y == z * z 
			|| x * x + z * z == y * y 
			|| y * y + z * z == x * x) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	} 
}
