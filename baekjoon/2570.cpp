#include <iostream>
using namespace std;

int sort[1001] = { 0, };
int main()
{
	int tc;
	int n = 0;
	cin >> tc;
	while (tc--) cin >> sort[n++];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sort[i] < sort[j]) swap(sort[i], sort[j]);
		}
	}
	int i = 0;
	while (n--) cout << sort[i++] << endl;
	return 0;
}
