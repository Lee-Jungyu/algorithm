#include <string>
#include <vector>

using namespace std;

bool arr[201];
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i + 1; j < numbers.size(); j++) {
            arr[numbers[i] + numbers[j]] = true;
        }
    }
    
    for(int i = 0; i < 201; i++) {
        if(arr[i]) answer.push_back(i);
    }
    
    return answer;
}
