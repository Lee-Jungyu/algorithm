#include <iostream>
#include <algorithm>
using namespace std;

int N;

class Point
{
public:
	int x;
	int y;

	Point() {
		x = 0; 
		y = 0;
	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	friend bool operator < (const Point p1, const Point p2) {
		if (p1.x < p2.x) {
			return true;
		}
		else if (p1.x == p2.x) {
			if (p1.y < p2.y) {
				return true;
			}
		}
		return false;
	}
};

Point p[200001];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	sort(p, p + N);
	
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", p[i].x, p[i].y);
	}
}
