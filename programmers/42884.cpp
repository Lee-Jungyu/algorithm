#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    
    int cam = routes[0][1];
    for(int i = 0; i < routes.size(); i++) {
        if(cam > routes[i][1]) cam = routes[i][1];
        if(cam < routes[i][0]) {
            cam = routes[i][1];
            answer++;
        }
    }
    
    return answer;
}
