#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> rest_time;
    int size = progresses.size();
    
    for(int i = 0; i < size; i++)
    {
        int rest = 100 - progresses[i];
        int time = rest % speeds[i] ? rest / speeds[i] + 1 : rest / speeds[i];
        
        rest_time.push_back(time);
    }
    
    int cnt = 1;
    int min = rest_time[0];
    for(int i = 1; i < size; i++)
    {
        if(min < rest_time[i]) {
            answer.push_back(cnt);
            min = rest_time[i];
            cnt = 0;
        }
        cnt++;
    }
    answer.push_back(cnt);
    
    return answer;
}
