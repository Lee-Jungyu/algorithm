#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class People {
public:
	string name;
	int age;
	int idx;
	bool operator<(const People p) {
		if (this->age != p.age) {
			if (this->age < p.age) return true;
			else return false;
		}
		else {
			if (this->idx < p.idx) return true;
			else return false;
		}
	}
}p[100000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].age >> p[i].name;
		p[i].idx = i;
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++) printf("%d %s\n", p[i].age, p[i].name.c_str());
	return 0;
}
