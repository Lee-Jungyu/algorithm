#include <iostream>
#include <queue>
using namespace std;

int heap[200002];
int cnt;

void push(int n) {
	cnt++;
	heap[cnt] = n;
	for (int i = cnt; i > 1; i /= 2) {
		if (heap[i] > heap[i / 2]) {
			int temp = heap[i];
			heap[i] = heap[i / 2];
			heap[i / 2] = temp;
		}
	}
	//for (int i = 1; i <= cnt; i++) cout << heap[i] << " ";
}

int pop() {
	if (cnt == 0) return 0;
	int value = heap[1];
	heap[1] = heap[cnt];
	for (int i = 1; i * 2 <= cnt;) {
		if (heap[i] < heap[i * 2] || heap[i] < heap[i * 2 + 1]) {
			if (heap[i * 2] < heap[i * 2 + 1]) {
				int temp = heap[i * 2 + 1];
				heap[i * 2 + 1] = heap[i];
				heap[i] = temp;
				i = i * 2 + 1;
			}
			else {
				int temp = heap[i * 2];
				heap[i * 2] = heap[i];
				heap[i] = temp;
				i = i * 2;
			}
		}
		else break;
	}
	//for (int i = 1; i < cnt; i++) cout << heap[i] << " ";
	heap[cnt] = 0;
	cnt--;
	return value;
}
int main() {
	int n;
    int num;
    scanf("%d", &n);
	cnt = 0;
	for (int i = 0; i < n + 1; i++) heap[i] = 0;

	for (int i = 0; i < n; i++) {
        scanf("%d", &num);
		if (num == 0) {
            printf("%d\n", pop());
		}
		else push(num);
	}
	return 0;
}
