#include <iostream>
#include <algorithm>
#include <vector>
#define _pair pair<int,int>
using namespace std;

int P, F;
vector<_pair> v;
vector<int> tmp[400001];
int result = 0;

void input()
{
	int n;
	scanf("%d %d", &P, &F);

	for (int i = 0; i < P; i++) {
		scanf("%d", &n);
		v.push_back({ n, 0 });
	}
	for (int i = 0; i < F; i++) {
		scanf("%d", &n);
		v.push_back({ n, 1 });
	}
}

void solve()
{
	sort(v.begin(), v.end());

	int level, max_level, min_level;
	max_level = min_level = level = 200000;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second) { //fire truck
			tmp[level++].push_back(v[i].first);
			if (max_level < level) max_level = level;
		}
		else { //pump 
			tmp[--level].push_back(v[i].first);
			if (min_level > level) min_level = level;
		}
	}

	for (int i = min_level; i < max_level; i++)
	{
		int len = 0;
		for (int j = 1; j < tmp[i].size(); j += 2) {
			len += tmp[i][j] - tmp[i][j - 1];
		}

		int _min = len;

		if (tmp[i].size() % 2) {

			for (int j = tmp[i].size() - 1; j > 0 ; j -= 2) {
				len += tmp[i][j] - tmp[i][j - 1] - (tmp[i][j - 1] - tmp[i][j - 2]);
				if (_min > len) _min = len;
			}
		}

		result += _min;
	}
}

void output()
{
	printf("%d\n", result);
}

int main() {
	input();
	solve();
	output();
}
