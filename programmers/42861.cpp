#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int getParent(vector<int>& parent, int n) {
    if(parent[n] == n) return n;
    return parent[n] = getParent(parent, parent[n]);
}

void unionParent(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool findParent(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    if(a == b) return true;
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<bool> visited(n, false);
    vector<int> parent(n);
    
    for(int i = 0; i < n; i++) parent[i] = i;

    sort(costs.begin(), costs.end(), cmp);
    
    for(int i = 0; i < costs.size(); i++) {
        if(findParent(parent, costs[i][0], costs[i][1])) continue;
        answer += costs[i][2];
        unionParent(parent, costs[i][0], costs[i][1]);
    }
    
    return answer;
}
