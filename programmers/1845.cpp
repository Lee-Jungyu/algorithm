#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int size = nums.size();
    int cnt = 0;
    int answer = 0;
    map<int, bool> type_hash;
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(!type_hash[nums[i]]) {
            type_hash[nums[i]] = true;
            cnt++;
        }
    }
    
    answer = size / 2 >= cnt ? cnt : size / 2;
    
    return answer;
}
