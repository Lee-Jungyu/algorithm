#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);;


	int N, M;
	cin >> M >> N;

	int sum = 0;
	int min = -1;

	for (int i = 1; i <= 10000; i++) {
		if (i * i > N) break;
		if (i * i < M) continue;
		if (min == -1) min = i * i;
		sum += i * i;
	}

	if (min == -1) {
		cout << -1 << endl;
	}
	else {
		cout << sum << endl;
		cout << min << endl;
	}

}
