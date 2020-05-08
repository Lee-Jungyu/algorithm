#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    int a = 0;
    for(int i = 0; i < n; i++)
    {
        a = arr1[i] | arr2[i];
        int size = n;
        string str = "";
        while(size--) {
            if(a % 2) {
                str = "#" + str;
            }
            else {
                str = " " + str;
            }
            a = a >> 1;
        }
        answer.push_back(str);
    }
    return answer;
}
