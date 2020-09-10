#include <string>
#include <vector>

using namespace std;

bool arr[1000001];
int solution(int n) {
    int answer = 0;
    
    for(int i = 2; i <= n; i++){
        if(arr[i] == true) continue;
        answer++;
        for(int j = 2 * i; j <= n; j += i) {
            arr[j] = true;
        }
    }
    
    return answer;
}
