#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    int total_size = brown + yellow;
    
    int i, j;
    for(i = 3; i <= total_size/ 3 ; i++) {
        if(total_size % i) continue;
        
        j = total_size / i;
        if(i < j) continue;
        
        if(yellow == (i - 2) * (j - 2)) break;
    }
    
    return {i, j};
}
