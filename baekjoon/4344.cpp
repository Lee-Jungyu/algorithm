#include <iostream>
using namespace std;

int c[1000] = { 0, };
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) cin >> c[j];
		int sum = 0;
		for (int j = 0; j < n; j++) sum += c[j];
		double avg = sum / n;
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (avg < c[j]) cnt++;
		}
		printf("%0.3f%s\n", (double)cnt / n * 100,"%");
	}
	return 0;
}
