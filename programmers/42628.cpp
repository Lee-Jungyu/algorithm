#include <string>
#include <vector>

using namespace std;

class PriorityQueue {
public:
    vector<int> vec;
    
    PriorityQueue() { vec.push_back(0); }
    
    void push(int num) {
        int curr_idx = vec.size();
        vec.push_back(num);
        
        if(curr_idx % 2 == 0) {
            if(vec[curr_idx - 1] > vec[curr_idx]) {
                swap(vec[curr_idx - 1], vec[curr_idx]);
                curr_idx = curr_idx - 1;
            }
        }
        
        if(vec.size() > 3) {
            while(curr_idx > 2) {
                if(vec[curr_idx] < vec[((curr_idx - 1) / 2 - 1) / 2 + 1]) {
                    swap(vec[curr_idx], vec[((curr_idx - 1) / 2 - 1) / 2 + 1]);
                    curr_idx = ((curr_idx - 1) / 2 - 1) / 2 + 1;
                }
                else if(vec[curr_idx] > vec[((curr_idx - 1) / 2 - 1) / 2 + 2]) {
                    swap(vec[curr_idx], vec[((curr_idx - 1) / 2 - 1) / 2 + 2]);
                    curr_idx = ((curr_idx - 1) / 2 - 1) / 2 + 2;
                }
                else break;
            }
        }
    }
    
    int get_min() {
        if(vec.size() < 2) return 0;
        return vec[1];
    }
    
    int get_max() {
        if(vec.size() < 2) return 0;
        if(vec.size() == 2) return vec[1];
        return vec[2];
    }
    
    void min_pop() {
        if(vec.size() < 2) return;
        if(vec.size() == 2) vec.erase(vec.begin() + 1);
        else {
            swap(vec[1], vec[vec.size() - 1]);
            vec.erase(vec.end() - 1);
            int curr_idx = 1;
            while(curr_idx < vec.size()) {
                if(curr_idx * 2 + 1 < vec.size() && (curr_idx + 1) * 2 + 1 < vec.size()) {
                    int next_idx = vec[curr_idx * 2 + 1] < vec[(curr_idx + 1) * 2 + 1] ? curr_idx * 2 + 1 : (curr_idx + 1) * 2 + 1;
                    
                    if(vec[curr_idx] > vec[next_idx]) {
                        swap(vec[curr_idx], vec[next_idx]);
                        curr_idx = next_idx;
                    }
                    else break;
                }
                else if(curr_idx * 2 + 1 < vec.size()) {
                    int next_idx = curr_idx * 2 + 1;
                    
                    if(vec[curr_idx] > vec[next_idx]){
                        swap(vec[curr_idx], vec[next_idx]);
                        curr_idx = next_idx;
                    }
                    else break;
                }
                else {
                    break;
                }
            }
        }
    }
    
    void max_pop() {
        if(vec.size() < 2) return;
        if(vec.size() == 2) vec.erase(vec.begin() + 1);
        else if(vec.size() == 3) vec.erase(vec.begin() + 2);
        else {
            swap(vec[2], vec[vec.size() - 1]);
            vec.erase(vec.end() - 1);
            int curr_idx = 1;
            while(curr_idx < vec.size()) {
                if(curr_idx * 2 + 2 < vec.size() && (curr_idx - 1) * 2 + 2 < vec.size()) {
                    int next_idx = vec[curr_idx * 2 + 2] > vec[(curr_idx - 1) * 2 + 2] ? curr_idx * 2 + 2 : (curr_idx - 1) * 2 + 2;
                    
                    if(vec[curr_idx] > vec[next_idx]) {
                        swap(vec[curr_idx], vec[next_idx]);
                        curr_idx = next_idx;
                    }
                    else break;
                }
                else if((curr_idx - 1) * 2 + 2 < vec.size()) {
                    int next_idx = (curr_idx - 1) * 2 + 2;
                    
                    if(vec[curr_idx] > vec[next_idx]){
                        swap(vec[curr_idx], vec[next_idx]);
                        curr_idx = next_idx;
                    }
                    else break;
                }
                else {
                    break;
                }
            }
        }
    }
};

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    PriorityQueue pq;
    for(int i = 0; i < operations.size(); i++) {
        if(operations[i][0] == 'I') {
            int num = stoi(operations[i].substr(2, operations[i].length() - 2));
            pq.push(num);
        }
        if(operations[i][0] == 'D') {
            if(operations[i][2] == '-') {
                pq.min_pop();
            }
            else {
                pq.max_pop();
            }
        }
    }
    
    answer.push_back(pq.get_max());
    answer.push_back(pq.get_min());
    
    return answer;
}
