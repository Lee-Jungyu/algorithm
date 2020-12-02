#include <string>
#include <vector>

using namespace std;

int go_left(int pos, int length) {
    return (length + pos - 1) % length;
}

int go_right(int pos, int length) {
    return (pos + 1) % length;
}

int check_name(int* name, int length) {
    int sum = 0;
    for(int i = 0; i < length; i++) sum += name[i];
    return sum;
}

int solution(string name) {
    int answer = 0;
    int NAME[20];
    
    int curr_pos = 0;
    int length = name.length();
    
    //pos 별로 더해야 하는 값들 구함
    for(int i = 0; i < name.length(); i++) {
        NAME[i] = name[i] - 'A';
        if(NAME[i] > 12) {
            NAME[i] = 26 - NAME[i];
        }
    }
    
    //pos = 0일 때 값을 미리 더함
    answer += NAME[0];
    NAME[0] = 0;
    
    //각 위치에서 가장 가까운 A가 아닌 위치 찾기
    while(true) {
        if(check_name(NAME, length) == 0) break;
        
        int left = 1;
        int right = 1;
        int left_pos = curr_pos;
        int right_pos = curr_pos;
        while(NAME[left_pos = go_left(left_pos, length)] == 0) left++;
        while(NAME[right_pos = go_right(right_pos, length)] == 0) right++;
        
        if(left < right) {
            answer += left;
            answer += NAME[left_pos];
            NAME[left_pos] = 0;
            curr_pos = left_pos;
        }
        else {
            answer += right;
            answer += NAME[right_pos];
            NAME[right_pos] = 0;
            curr_pos = right_pos;
        }
    }
    
    
    return answer;
}
