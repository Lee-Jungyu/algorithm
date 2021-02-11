#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int alpha[26];

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); j++) {
            alpha[str[j] - 'A'] += pow(10, str.length() - j - 1);
        }
    }

    sort(alpha, alpha + 26, cmp);

    int result = 0;
    for(int i = 0; i < 10; i++) {
        result += alpha[i] * (9 - i);
    }

    cout << result << '\n';

}
