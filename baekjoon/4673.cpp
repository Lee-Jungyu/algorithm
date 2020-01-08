#include <iostream>
using namespace std;

void makeSelf(int i);
int self[10000] = { 0, };
int main() {

	for (int i = 1; i < 10000; i++) {
		makeSelf(i);
	}
	for (int i = 1; i < 10000; i++) {
		if (self[i] == 0) printf("%d\n",i);
	}
	return 0;
}

void makeSelf(int i) {
	int n = i + i / 10000 + (i / 1000) % 10 + (i / 100) % 10 + (i / 10) % 10 + i % 10;
	if (n < 10000) self[n] = 1;
}
