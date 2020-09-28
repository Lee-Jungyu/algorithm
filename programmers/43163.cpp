#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    int find_idx = 0;
    for(find_idx = 0; find_idx < words.size(); find_idx++) {
        if(words[find_idx] == target) break;
    }
    if(find_idx == words.size()) return 0;
    
    vector<int> dist(words.size(), 0);
    queue<pair<string, int>> q;
    q.push(make_pair(begin, 0));
    
    while(!q.empty() ) {
        pair<string, int> tmp = q.front();
        if(tmp.first == target) break;
        q.pop();
        for(int i = 0; i < words.size(); i++) {
            if(dist[i] == 0) {
                int match_cnt = 0;
                for(int j = 0; j < words[i].length(); j++) {
                    if(tmp.first[j] == words[i][j]) match_cnt++;
                }
                
                if(match_cnt == words[i].length() - 1) {
                    dist[i] = dist[tmp.second] + 1;
                    q.push(make_pair(words[i], i));
                }
            }
        }
    }
    
    if(q.front().first == target)
        return dist[q.front().second];
    
    return 0;
}
