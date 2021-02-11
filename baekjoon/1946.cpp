#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    
    while(T--) {
        vector<pair<int, int>> juniors;
        int N;
        cin >> N;

        for(int i = 0; i < N; i++) {
            pair<int, int> p;
            cin >> p.first >> p.second;
            juniors.push_back(p);
        }

        sort(juniors.begin(), juniors.end());

        pair<int, int> tmp;
        tmp = juniors[0];

        int result = 0;
        for(int i = 1; i < N; i++) {
            if(tmp.first < juniors[i].first && tmp.second < juniors[i].second){
                result++;
            }
            if(tmp.first > juniors[i].first)
                tmp.first = juniors[i].first;
            if(tmp.second > juniors[i].second)
                tmp.second = juniors[i].second;
        }

        cout << N - result << endl;
    }

}
