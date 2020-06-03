#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int arr1[5] = {1,2,3,4,5};
    int arr2[8] = {2,1,2,3,2,4,2,5};
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    int result[4] = {0,};
    for(int i = 0; i < answers.size(); i++)
    {
        if(arr1[i % 5] == answers[i]) result[1]++;
        if(arr2[i % 8] == answers[i]) result[2]++;
        if(arr3[i % 10] == answers[i]) result[3]++;
    }
    
    int max = 0;
    for(int i = 1; i <= 3; i++)
    {
        if(max < result[i]) max = result[i];
    }
    
    for(int i = 1; i <= 3; i++)
    {
        if(max == result[i]) answer.push_back(i);
    }
    
    return answer;
}
