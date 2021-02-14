#include <iostream>
using namespace std;

long long power(long long a, int b, int c) {
    if(b == 0) return 1;

    long long tmp = power(a, b / 2, c);
    if(b % 2) {
        return ((tmp * tmp) % c) * a % c;
    }
    else {
        return (tmp * tmp) % c;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;

    cout << power(a, b, c) << '\n';
    
    return 0;
}

// (a^b) % c -> (a % c)^b % c
// (a*b) % c -> (a % c) * (b % c) % c
// (a^2) % c -> (a % c) * (a % c) % c
