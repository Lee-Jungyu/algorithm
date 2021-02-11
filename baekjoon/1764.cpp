#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, bool> check;
vector<string> result;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    cin >> M;

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        check[str] = true;
    }

    for(int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if(check[str]) result.push_back(str);
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    
}
