#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer[7] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    int days[12] = {0,31,29,31,30,31,30,31,31,30,31,30};
    int sum = 0;
    for(int i = 0; i < a; i++)
        sum += days[i];
    sum+=b;
    
    
    return answer[sum%7];
}

