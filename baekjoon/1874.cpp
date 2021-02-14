#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
vector<char> arr;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    int curr = 0;
    bool check = true;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if(curr <= num) {
            while(curr != num) {
                curr++;
                arr.push_back('+');
                s.push(curr);
            }
            arr.push_back('-');
            s.pop();
        }
        else {
            if(s.top() > num) {
                check = false;
            }
            arr.push_back('-');
            s.pop();
        }
    }

    if(!check) {
        cout << "NO\n";
        return 0;
    }

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << "\n";
    }
} 
