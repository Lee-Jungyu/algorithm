#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<set<char>, int> check;
map<int, int> top_cnt_of_check;
map<int, set<string>> array_of_check;
void find_set(int idx, int set_size, int set_cnt, string orders, vector<bool> visited, set<char> menu_set) {
    menu_set.insert(orders[idx]);
    visited[idx] = true;
    
    if(set_cnt == set_size) {
        check[menu_set]++;
        if(top_cnt_of_check[set_size] < check[menu_set] && check[menu_set] > 1) {
            top_cnt_of_check[set_size] = check[menu_set];
            array_of_check[set_size].clear();
            string tmp = "";
            for(auto it = menu_set.begin(); it != menu_set.end(); it++) {
                tmp += *it;
            }
            array_of_check[set_size].insert(tmp);
        }
        if(top_cnt_of_check[set_size] == check[menu_set]) {
            string tmp = "";
            for(auto it = menu_set.begin(); it != menu_set.end(); it++) {
                tmp += *it;
            }
            array_of_check[set_size].insert(tmp);
        }
        
        return;
    }
    
    for(int i = idx + 1; i < orders.length() - set_size + set_cnt + 1; i++) {
        if(visited[i] != true) {
            find_set(i, set_size, set_cnt + 1, orders, visited, menu_set);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i = 0; i < course.size(); i++) {
        int set_size = course[i];
        
        for(int j = 0; j < orders.size(); j++) {
            if(orders[j].length() < set_size) continue;
            
            vector<bool> visited(orders[j].size(), false);
            set<char> menu_set;
            for(int k = 0; k < orders[j].length() - set_size + 1; k++) {
                find_set(k, set_size, 1, orders[j], visited, menu_set);
            }
        }
    }
    
    for(auto it = array_of_check.begin(); it != array_of_check.end(); it++) {
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            answer.push_back(*it2);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    
    return answer;
}
