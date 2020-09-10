#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 0;
    int cnt = number.length() - k;
    while (cnt) {
        int max = number[idx];
        for (int i = idx; i <= number.length() - cnt; i++) {
            if (number[idx] < number[i]) idx = i;
        }

        answer += number[idx];
        idx++;
        cnt--;
    }

    return answer;
}
