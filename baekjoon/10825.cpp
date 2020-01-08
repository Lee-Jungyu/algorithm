#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student {
public:
	string name;
	int kor;
	int math;
	int eng;

	friend bool operator<(const Student s1, const Student s2) {
		if (s1.kor != s2.kor) {
			if (s1.kor > s2.kor) return true;
			else return false;
		}
		else if (s1.eng != s2.eng) {
			if (s1.eng < s2.eng) return true;
			else return false;
		}
		else if (s1.math != s2.math) {
			if (s1.math > s2.math) return true;
			else return false;
		}
		else {
			if (s1.name < s2.name) return true;
			else return false;
		}
	}
};

int cmp(Student& s1, Student&s2) {
	return s1 < s2;
}

Student s[100000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i].name >> s[i].kor >> s[i].eng >> s[i].math;
	sort(s, s + n, cmp);
	for (int i = 0; i < n; i++) printf("%s\n", s[i].name.c_str());
	return 0;
}
