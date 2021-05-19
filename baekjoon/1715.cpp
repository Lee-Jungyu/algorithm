#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		pq.push(num);
	}

	int sum = 0;
	while (pq.size() > 1) {
		int tmp1 = pq.top(); pq.pop();
		int tmp2 = pq.top(); pq.pop();
		int tmp3 = tmp1 + tmp2;

		sum += tmp3;
		pq.push(tmp3);
	}

	cout << sum << endl;

	return 0;
}
