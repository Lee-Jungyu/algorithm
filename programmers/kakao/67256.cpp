#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int curr_L = 10;
    int curr_R = 12;
    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] % 3 == 1) {
            answer += "L";
            curr_L = numbers[i];
        }
        else if(numbers[i] % 3 == 0 && numbers[i] != 0) {
            answer += "R";
            curr_R = numbers[i];
        }
        else {
            int tmp = numbers[i];
            if(numbers[i] == 0) tmp = 11;

            int dist_L, dist_R;

            if(curr_L % 3 == 1) dist_L = abs(tmp - curr_L - 1) / 3 + 1;
            else dist_L = abs(tmp - curr_L) / 3;

            if(curr_R % 3 == 0) dist_R= abs(tmp - curr_R + 1) / 3 + 1;
            else dist_R = abs(tmp - curr_R) / 3;

            if(dist_L == dist_R) {
                if(hand[0] == 'l') {
                    answer += "L";
                    curr_L = tmp;
                }
                else {
                    answer += "R";
                    curr_R = tmp;
                }
            }
            else {
                if(dist_L < dist_R) {
                    answer += "L";
                    curr_L = tmp;
                }
                else {
                    answer += "R";
                    curr_R = tmp;
                }
            }
        }
    }
    return answer;
}
