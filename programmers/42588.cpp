#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int arr[101];
    int flag = heights.size() - 1;
    for(int i = heights.size() - 1; i >= 0; i--)
    {
        int check = 1;
        for(int j = i - 1; j >= 0; j--){
            if(heights[i] < heights[j]) {
                arr[flag--] = j + 1;
                check = 0;
                break;
            } 
        }
        if(check)
            arr[flag--] = 0;
    }
    for(int i = 0; i < heights.size(); i++)
    {
        answer.push_back(arr[i]);
    }
    return answer;
}
