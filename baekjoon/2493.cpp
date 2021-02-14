#include <iostream>
#include <stack>
using namespace std;

int building[500002];
int reception[500002];
stack<pair<int, int>> s;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> building[i];
    }

    for(int i = 1; i <= N; i++) {
        if(s.empty()) {
            s.push({i, building[i]});
        }
        else if(s.top().second < building[i]) {
            while(!s.empty()) {
                if(s.top().second >= building[i]) break;
                s.pop();
            }
            if(!s.empty()) reception[i] = s.top().first;
            s.push({i, building[i]});
        }
        else {
            reception[i] = s.top().first;
            s.push({i, building[i]});
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << reception[i] << " ";
    }

    return 0;
} 
