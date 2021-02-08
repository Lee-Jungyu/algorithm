#include <iostream>
using namespace std;

bool arr[1001] = {false, };
int main(){
    int N, K, cnt = 0;
    cin >> N >> K;

    for(int i = 2; i <= N; i++) {
        if(arr[i]) continue;
        arr[i] = true;
        cnt++;
        if(cnt == K) {
            cout << i << endl;
            break;
        }
        for(int j = i + i; j <= N; j += i) {
            if(arr[j]) continue;
            arr[j] = true;
            cnt++;
            if(cnt == K) {
                cout << j << endl;
                break;
            }
        }
        if(cnt == K) break;
    }
}
