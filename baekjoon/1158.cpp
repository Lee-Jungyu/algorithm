#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int main() {
    int N, K;

    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        q.push(i);
    }

    int cnt = 0;
    cout << "<";
    while(N) {
        cnt++;
        if(cnt == K) {
            cout << q.front();
            if(N != 1) cout << ", ";
            q.pop();
            N--;
            cnt = 0;
            continue;
        }

        int n = q.front();
        q.pop();
        q.push(n);
    }
    cout << ">\n";
} 
