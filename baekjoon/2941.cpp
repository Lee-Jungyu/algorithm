#include <iostream>
#include <string.h>
using namespace std;

char croatia[101];
int cnt = 0;
int main()
{
	scanf("%s", croatia);
	int length = strlen(croatia);

	for (int i = 0; i < length; i++) {
		if (croatia[i] == 'd') {
			
			if (i < length - 2) {
				if (croatia[i + 1] == 'z' && croatia[i + 2] == '=')
					i += 2;
			}

			if (i < length - 1) {
				if (croatia[i + 1] == '-')
					i += 1;
			}

			cnt++;
		}

		else if (croatia[i] == 'c') {

			if (i < length - 1) {
				if (croatia[i + 1] == '=' || croatia[i + 1] == '-') {
					i += 1;
				}
			}
			
			cnt++;
		}

		else if (croatia[i] == 'l') {

			if (i < length - 1) {
				if (croatia[i + 1] == 'j') i += 1;
			}

			cnt++;
		}

		else if (croatia[i] == 'n') {

			if (i < length - 1) {
				if (croatia[i + 1] == 'j') i += 1;
			}

			cnt++;
		}

		else if (croatia[i] == 's') {

			if (i < length - 1) {
				if (croatia[i + 1] == '=') i += 1;
			}

			cnt++;
		}

		else if (croatia[i] == 'z') {

			if (i < length - 1) {
				if (croatia[i + 1] == '=') i += 1;
			}

			cnt++;
		}

		else cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
