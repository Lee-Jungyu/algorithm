#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    vector<bool> saved(people.size(), false);
    sort(people.begin(), people.end());

    int min_idx = 0;
    int max_idx = people.size() - 1;
    int cnt = people.size();
    while (cnt) {
        int boat_size = limit;
        saved[max_idx] = true;
        boat_size -= people[max_idx];
        cnt--;

        while (boat_size >= people[min_idx] && max_idx != min_idx) {
            int tmp_idx = min_idx;
            for (int i = min_idx; i < max_idx; i++) {
                if (saved[i]) continue;
                if (boat_size < people[i]) break;
                tmp_idx = min_idx;
            }

            boat_size -= people[tmp_idx];
            saved[tmp_idx] = true;
            if (tmp_idx == min_idx) {
                while (min_idx <= max_idx) {
                    if (saved[min_idx]) min_idx++;
                    else break;
                }
            }
            cnt--;
        }

        while (max_idx) {
            if (saved[max_idx]) max_idx--;
            else break;
        }
        answer++;
    }

    return answer;
}
