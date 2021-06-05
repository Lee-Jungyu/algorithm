#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, set = 9999, val = 9999, sum = 0;

	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		int num1, num2;
		cin >> num1 >> num2;

		if (num1 < set) set = num1;
		if (num2 < val) val = num2;
	}

	while (N) {
		if (N >= 6) {
			if (set <= val * 6) {
				N -= 6;
				sum += set;
			}
			else {
				N -= 6;
				sum += (val * 6);
			}
		}
		else {
			if (set <= val * N) {
				N = 0;
				sum += set;
			}
			else {
				sum += (val * N);
				N = 0;
			}
		}
	}

	cout << sum << endl;
 
	return 0;
}
