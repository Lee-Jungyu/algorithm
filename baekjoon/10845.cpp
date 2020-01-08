#include <iostream>
#include <string>
using namespace std;

int q[10000];
int front, rear;

int empty() {
	if (front == rear) return 1;
	else return 0;
}

int size() {
	return rear - front;
}

void push(int x) {
	q[rear] = x;
	rear++;
}

int pop() {
	if (empty()) return -1;
	else {
		int f = front;
		front++;
		return q[f];
	}
}

int Front() {
	if (empty()) return -1;
	else return q[front];
}

int Back() {
	if (empty()) return -1;
	else {
		return q[rear - 1];
	}
}

int main() {
	rear = 0, front = 0;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string order;
		int num;
		cin >> order;
		if (order == "push") {
			cin >> num;
			push(num);
		}
		else if (order == "pop") {
			cout << pop() << endl;
		}
		else if (order == "size") {
			cout << size() << endl;
		}
		else if (order == "empty") {
			cout << empty() << endl;
		}
		else if (order == "front") {
			cout << Front() << endl;
		}
		else if (order == "back") {
			cout << Back() << endl;
		}
	}
}
