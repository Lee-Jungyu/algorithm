#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int ball = 1;
    int m;
    cin >> m;
    
    while(m--) {
        int num1, num2;
        cin >> num1 >> num2;

        if(ball == num1) {
            ball = num2;
        }
        else if(ball == num2) {
            ball = num1;
        }
    }

    cout << ball << endl;
}

// 야바위네
