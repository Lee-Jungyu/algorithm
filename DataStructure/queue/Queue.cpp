#include <iostream>
using namespace std;

class Queue {
private:
	int* _queue;
	int _max;
	int _front;
	int _rear;
	
	void queueSizeUp() {
		int* tmp = new int[_max * 2];
		
		for (int i = _front; i < _rear; i++) {
			tmp[i - _front] = _queue[i];
		}

		int* deleteQueue = _queue;
		_queue = tmp;

		delete[] deleteQueue;

		_max *= 2;
		_rear = _rear - _front;
		_front = 0;

	}

public:
	Queue() {
		_max = 10;
		_queue = new int[_max];
		_front = 0;
		_rear = 0;
	}

	Queue(int size) {
		_max = size;
		_queue = new int[_max];
		_front = 0;
		_rear = 0;
	}

	~Queue() {
		delete[] _queue;
	}

	void push(int data) {
		if (isFull()) {
			queueSizeUp();
		}


		_queue[_rear++] = data;
	}

	void pop() {
		if (isEmpty()) {
			cout << "Empty\n";
			return;
		}

		_front++;
	}

	int front() {
		if (isEmpty()) {
			cout << "Empty\n";
			return -1;
		}

		return _queue[_front];
	}

	int rear() {
		if (isEmpty()) {
			cout << "Empty\n";
			return -1;
		}

		return _queue[_rear - 1];
	}

	bool isEmpty() {
		return _front == _rear;
	}

	bool isFull() {
		return _rear == _max;
	}

	int size() {
		return _rear - _front;
	}
};

int main()
{
	Queue q;

	for (int i = 0; i < 25; i++) {
		q.push(i);
		cout << "push: " << q.rear() << endl;
	}
	cout << "size: " << q.size() << endl;

	while (!q.isEmpty()) {
		cout << "pop: " << q.front() << endl;
		q.pop();
	}
}
