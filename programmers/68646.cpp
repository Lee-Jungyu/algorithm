#include <string>
#include <vector>

using namespace std;

int min_left[1000001];
int min_right[1000001];

int solution(vector<int> a) {
    int answer = 0;
    int size = a.size();
    
    if(a.size() == 1 || a.size() == 2) return a.size();
    
    min_left[0] = a[0];
    min_right[size - 1] = a[size - 1];
    
    for(int i = 1; i < a.size(); i++) {
        if(min_left[i - 1] > a[i]) min_left[i] = a[i];
        else min_left[i] = min_left[i - 1];
    }
    
    for(int i = size - 2; i >= 0; i--) {
        if(min_right[i + 1] > a[i]) min_right[i] = a[i];
        else min_right[i] = min_right[i + 1];
    }
    
    for(int i = 1; i < size - 1; i++) {
        if(min_left[i - 1] >= a[i] || min_right[i + 1] >= a[i]) answer++;
    }
    
    answer += 2;
    
    return answer;
}
