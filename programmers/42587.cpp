#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<bool> visited(priorities.size(), false);
    vector<int> p = priorities;
    
    sort(p.begin(), p.end(), cmp);
    
    int idx = 0;
    while(true) {
        if(priorities[idx] == p[0]) {
            visited[idx] = true;
            p.erase(p.begin());
            answer++;
            if(idx == location) break;
        }
        
        idx = (idx + 1) % priorities.size();
    }
    
    return answer;
}
