#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string remainder[3] = {"4", "1", "2"};
    
    while(n > 0)
    {
        string r = remainder[n % 3];
        if(n % 3 == 0) n--;
        n /= 3;
        answer = r + answer;
    }
    
    return answer;
}
