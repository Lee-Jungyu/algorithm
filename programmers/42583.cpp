#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    vector<int> bridge;
    
    for(int i = 0; i < bridge_length; i++) {
        bridge.push_back(0);
    }
    
    while(truck_weights.size()) {
        
        if(bridge.size() == bridge_length) {
            answer++;
            bridge.erase(bridge.begin());
            continue;
        }
        
        int bridge_weight = 0;
        for(int i = 0; i < bridge.size(); i++)
        {
            bridge_weight += bridge[i];
        }
        
        if(bridge_weight == 0) {
            bridge.push_back(truck_weights[0]);
            truck_weights.erase(truck_weights.begin());
        }
        else {
            if(bridge_weight + truck_weights[0] <= weight) {
                bridge.push_back(truck_weights[0]);
                truck_weights.erase(truck_weights.begin());
            }
            else {
                bridge.push_back(0);
            }
        }
    }
    
    answer = answer + bridge.size();
    
    return answer;
}
