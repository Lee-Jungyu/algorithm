#include <iostream>
using namespace std;

int p[1000001];
int main() 
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		bool check = false;
		for (int i = 2; i <= 64; i++)
		{
			check = true;
			int p_idx = 0;
			int num = n;
			while (num != 0) {
				p[p_idx++] = num % i;
				num /= i;
			}
			int mid = p_idx / 2;
			for (int j = 0; j < mid; j++)
			{
				if (p[j] != p[p_idx - j - 1]) {
					check = false;
					j = mid;
				}
			}
			if (check) break;
		}
		if (check) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
