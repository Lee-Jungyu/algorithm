#include <iostream>
#include <algorithm>
using namespace std;

int rope[100001];

int main()
{
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> rope[i];
    }

    sort(rope, rope + N);

    int max_value = 0;
    for(int i = 0; i < N; i++) {
        if(max_value < rope[i] * (N - i)) max_value = rope[i] * (N - i);
    }

    cout << max_value << endl;
}
