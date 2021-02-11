#include <iostream>
using namespace std;

int coin[6] = {500, 100, 50, 10, 5, 1};
int main() {
    int total = 1000;
    int result = 0;
    int idx = 0;
    int money;
    cin >> money;

    total -= money;

    while(total) {
        result += (total / coin[idx]);
        total %= coin[idx];
        idx++;
    }

    cout << result << endl;
}
