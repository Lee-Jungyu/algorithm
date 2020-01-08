#include <iostream>
using namespace std;


int main()
{
	unsigned int n;
	scanf("%d", &n);
	
	if (n == 1) { printf("%d\n", 1); return 0; }

	int idx = 2;
	int min = 1;
	for (int i = 1; ; i++) {
		for (int j = 0; j < 6 * i; j++) {
			min = i + 1;
			if (idx >= n) { printf("%d", min); return 0; }
			idx++;
		}
	}
	
	return 0;
}
