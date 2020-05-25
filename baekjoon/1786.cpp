#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> KMP(string T, string P)
{
    vector<int> result;
    vector<int> pi(P.length(), 0);

    int j = 0;
    for(int i = 1; i < P.length(); i++)
    {
        while(j > 0 && P[i] != P[j]) j = pi[j - 1];
        if(P[i] == P[j]) pi[i] = ++j;
    }

    j = 0;
    for(int i = 0; i < T.length(); i++)
    {
        while(j > 0 && T[i] != P[j]) j = pi[j - 1];
        if(T[i] == P[j]) {
            if(j == P.length() - 1) {
                result.push_back(i - P.length() + 2);
                j = pi[j];
            }
            else j++;
        }
    }
    return result;
}

int main()
{
    string T, P;
    vector<int> result;

    getline(cin, T);
    getline(cin, P);

    result = KMP(T, P);

    cout << result.size() << "\n";
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << "\n";
}

//복습 필요
