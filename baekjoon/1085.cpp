#include <iostream>
using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int X = x < w - x ? x : w - x;
	int Y = y < h - y ? y : h - y;
	int d = X > Y ? Y : X;
	cout << d << endl;
}
