#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> arr;
int result[1000001];

bool cmp1(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}

bool cmp2(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		pair<int, int> p;
		cin >> p.second;
		p.first = i;

		arr.push_back(p);
	}

	sort(arr.begin(), arr.end(), cmp1);

	int flag = 0;
	result[arr[0].first] = flag;
	for (int i = 1; i < N; i++) {
		if (arr[i - 1].second == arr[i].second) {
			result[arr[i].first] = flag;
		}
		else {
			result[arr[i].first] = ++flag;
		}
	}

	sort(arr.begin(), arr.end(), cmp2);

	for (int i = 0; i < N; i++) {
		cout << result[i] << ' ';
	}

	return 0;
}
