#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if(n == 0 || n == 1) return n;
    
    int answer = 0;
    
    answer += 1 + n;
    
    for(int i = 2; i <= n / 2; i++)
        if(n % i == 0) answer += i;
    
    return answer;
}
