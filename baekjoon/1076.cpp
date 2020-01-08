#include <iostream>
#include <cstring>
using namespace std;

int main() {
	long long value = 0;
	char c[100];
	for (int i = 0; i < 3; i++) {
		cin.getline(c, 99);
		if (i == 0 || i == 1) {
			if (i == 1) {
				value *= 10;
			}
			if (!strcmp(c,"black")) {
				value += 0;
			}
			else if (!strcmp(c, "brown")) {
				value += 1;
			}
			else if (!strcmp(c, "red")) {
				value += 2;
			}
			else if (!strcmp(c, "orange")) {
				value += 3;
			}
			else if (!strcmp(c, "yellow")) {
				value += 4;
			}
			else if (!strcmp(c, "green")) {
				value += 5;
			}
			else if (!strcmp(c,"blue")) {
				value += 6;
			}
			else if (!strcmp(c, "violet")) {
				value += 7;
			}
			else if (!strcmp(c, "grey")) {
				value += 8;
			}
			else if (!strcmp(c, "white")) {
				value += 9;
			}
		}
		else if (i == 2) {
			if (!strcmp(c, "black")) {
				value *= 1;
			}
			else if (!strcmp(c, "brown")) {
				value *= 10;
			}
			else if (!strcmp(c, "red")) {
				value *= 100;
			}
			else if (!strcmp(c, "orange")) {
				value *= 1000;
			}
			else if (!strcmp(c, "yellow")) {
				value *= 10000;
			}
			else if (!strcmp(c, "green")) {
				value *= 100000;
			}
			else if (!strcmp(c, "blue")) {
				value *= 1000000;
			}
			else if (!strcmp(c, "violet")) {
				value *= 10000000;
			}
			else if (!strcmp(c, "grey")) {
				value *= 100000000;
			}
			else if (!strcmp(c, "white")) {
				value *= 1000000000;
			}
		}
	}
	cout << value << endl;
}
