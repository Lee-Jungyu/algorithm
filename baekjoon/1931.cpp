#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Conf {
    int start_time;
    int end_time;
};

vector<Conf> conf_vec;

bool cmp(Conf a, Conf b) {
    if(a.end_time == b.end_time) {
        return a.start_time < b.start_time;
    }
    return  a.end_time < b.end_time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;

        Conf conf;
        conf.start_time = s;
        conf.end_time = e;
        conf_vec.push_back(conf);
    }

    sort(conf_vec.begin(), conf_vec.end(), cmp);

    int curr = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(curr > conf_vec[i].start_time) {
            continue;
        }
        curr = conf_vec[i].end_time;
        cnt++;
    }

    cout << cnt << '\n';
}
