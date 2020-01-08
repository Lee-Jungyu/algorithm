#include <iostream>
#include <algorithm>
using namespace std;

class Point {
public:
	int x;
	int y;
	friend bool operator<(const Point& p1, const Point& p2) {
		if (p1.y != p2.y) {
			if (p1.y < p2.y)
				return true;
			else
				return false;
		}
		else {
			if (p1.x < p2.x)
				return true;
			else
				return false;
		}
	}
};

int cmp(const Point& p1, const Point& p2) {
	return p1 < p2;
}

int main() 
{
	Point p[100000];
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) scanf("%d%d",&p[i].x,&p[i].y);
	sort(p, p + t, cmp);
	for (int i = 0; i < t; i++) printf("%d %d\n",p[i].x,p[i].y);
	return 0;
}
