#include <string>

using namespace std;

int score[3];
int solution(string dartResult) {
    int answer = 0;
    int flag = -1;
    
    for(int i = 0; i < dartResult.length(); i++)
    {
        if(dartResult[i] == 'S') {
            continue;
        }
        else if(dartResult[i] == 'D') {
            score[flag] = score[flag] * score[flag];
        }
        else if(dartResult[i] == 'T') {
            score[flag] = score[flag] * score[flag] * score[flag];
        }
        else if(dartResult[i] == '*') {
            if(flag == 0) {
                score[flag] *= 2;
            }
            else {
                score[flag] *= 2;
                score[flag - 1] *= 2;
            }
        }
        else if(dartResult[i] == '#') {
            score[flag] *= -1;
        }
        else {
            flag++;
            if(dartResult[i] == '1' && dartResult[i + 1] == '0') {
                score[flag] += 10;
                i++;
            }
            else {
                score[flag] += dartResult[i] - '0';
            }
        }
    }
    
    answer = score[0] + score[1] + score[2];
    return answer;
}
