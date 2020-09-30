#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[10001];

bool cmp(vector<string> a, vector<string> b) {
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

bool dfs(int size, int cnt, int idx, vector<vector<string>> tickets, vector<string>& answer) {
    
    answer.push_back(tickets[idx][1]);
    
    if(size == cnt) {
        return true;
    }
    
    bool chk = false;
    for(int i = 0; i < tickets.size(); i++) {
        if(!visited[i] && tickets[idx][1] == tickets[i][0]) {
            visited[i] = true;
            chk = dfs(size, cnt + 1, i, tickets, answer);
            if(chk) return true;
            visited[i] = false;
        }
    }
    
    answer.erase(answer.end() - 1);
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end(), cmp);
    
    int start_idx = -1;
    int last_idx = -1;
    for(int i = 0; i < tickets.size(); i++) {
        if(start_idx == -1 && tickets[i][0] == "ICN") start_idx = i;
        if(start_idx != -1 && tickets[i][0] != "ICN") {
            last_idx = i;
            break;
        }
    }
    
    for(int i = start_idx; i < last_idx; i++) {
        visited[i] = true;
        answer.push_back(tickets[i][0]);
        bool chk = dfs(tickets.size(), 1, i, tickets, answer);
        if(chk) return answer;
        answer.clear();
        visited[i] = false;
    }
    
    return answer;
}
