#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += vec[i] * (n - i);
    }

    cout << sum << endl;
}
