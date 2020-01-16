#include <iostream>
#include <cstring>
using namespace std;

int q[2000001];
int front, rear;

bool empty() {
	if (front == rear) return true;
	else return false;
}

int main() {
	rear = 0, front = 0;
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
        char order[6];
        scanf("%s", order);
		if (!strcmp(order,"push")) {
            int num;
            scanf("%d", &num);
			q[rear++] = num;
		}
		else if (!strcmp(order,"pop")) {
	        if (empty()) printf("-1\n");
	        else printf("%d\n", q[front++]);
		}
		else if (!strcmp(order,"size")) {
            printf("%d\n", rear - front);
		}
		else if (!strcmp(order,"empty")) {
            printf("%d\n", empty());
		}
		else if (!strcmp(order,"front")) {
            if (empty()) printf("-1\n");
	        else printf("%d\n", q[front]);
		}
		else if (!strcmp(order,"back")) {
            if (empty()) printf("-1\n");
	        else printf("%d\n", q[rear - 1]);
		}
	}
}
