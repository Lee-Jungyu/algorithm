#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int curr_time = 0;
    int job_idx = 0;
    
    sort(jobs.begin(), jobs.end());
    curr_time = jobs[0][0];
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    while(job_idx < jobs.size() || !pq.empty()) {
        if(job_idx < jobs.size()) {
            if(curr_time >= jobs[job_idx][0]) {
                pq.push(jobs[job_idx++]);
                continue;
            }
        }
        if(!pq.empty()) {
            curr_time += pq.top()[1];
            answer += curr_time - pq.top()[0];
            pq.pop();
        }
        else {
            curr_time = jobs[job_idx][0];
        }
    }
    
    return answer / jobs.size();
}
