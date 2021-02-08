#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> vec;

    while(N != 1) {
        for(int i = 2; i <= N; i++) {
            if(N % i) continue;
            vec.push_back(i);
            N /= i;
            break;
        }
    }

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << '\n';
    }

    return 0;
}
