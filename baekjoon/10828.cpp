#include <iostream>
#include <string>
using namespace std;

int q[10000];
int top;


int empty() {
	if (top == -1) return 1;
	else return 0;
}

void push(int num) {
	q[++top] = num;
}

int pop() {
	if (empty()) return -1;
	return q[top--];
}

int Top() {
	if (empty()) return -1;
	return q[top];
}

int size() {
	return top + 1;
}

int main() {
	top = -1;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string order;
		cin >> order;
		if (order == "push") {
			int num;
			cin >> num;
			push(num);
		}
		if (order == "pop") {
			cout << pop() << endl;
		}
		if (order == "top") {
			cout << Top() << endl;
		}
		if (order == "size") {
			cout << size() << endl;
		}
		if (order == "empty") {
			cout << empty() << endl;
		}
	}
}
