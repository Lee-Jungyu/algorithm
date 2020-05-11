#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int stage[502];
int total[502];

bool cmp(pair<double, int> a, pair<double, int> b)
{
    if(a.first != b.first)
        return a.first > b.first;
    else
        return a.second < b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> fail_rate;
    
    for(int i = 0; i < stages.size(); i++)
    {
        stage[stages[i]]++;
    }
   
    total[N + 1] = stage[N + 1];
    
    for(int i = N; i > 0; i--)
    {
        total[i] = total[i + 1] + stage[i];
    }
    
    for(int i = 1; i <= N; i++)
    {
        if(total[i] != 0) {
            fail_rate.push_back(make_pair((double)(total[i] - total[i + 1]) / total[i], i));
        }
        else {
            fail_rate.push_back(make_pair(0, i));
        }
    }
    
    sort(fail_rate.begin(), fail_rate.end(), cmp);
    
    for(int i = 0; i < fail_rate.size(); i++)
    {
        answer.push_back(fail_rate[i].second);
    }
    return answer;
}
