#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getMinute(string hour, string minute)
{
    int h = 0, m = 0;
    for(int i = 0; i < 2; i++)
    {
        h *= 10;
        h += hour[i] - '0';
        m *= 10;
        m += minute[i] - '0';
    }
    
    return h * 60 + m;
}

string getTime(int minute)
{
    int min = minute % 60;
    int hour = minute / 60;
    
    string mstr = "";
    string hstr = "";
    
    if(hour == 0) hstr += "00";
    else if(hour < 10) {
        hstr += '0';
        hstr += (char)(hour % 10 + '0');
    }
    else {
        while(hour) {
            hstr = (char)(hour % 10 + '0') + hstr;
            hour /= 10;
        }
    }
    
    if(min == 0) mstr += "00";
    else if(min < 10) {
        mstr += '0';
        mstr += (char)(min % 10 + '0');
    }
    else {
        while(min) {
            mstr = (char)(min % 10 + '0') + mstr;
            min /= 10;
        }
    }
    
    return hstr + ":" + mstr;
}

string solution(int n, int t, int m, vector<string> timetable) {
    
    int last_time = 540 + (n - 1) * t;
    
    vector<int> minute_table;
    for(int i = 0; i < timetable.size(); i++)
    {
        string hour = "";
        hour = timetable[i].substr(0, 2);
        string minute = "";
        minute = timetable[i].substr(3, 2);
        minute_table.push_back(getMinute(hour, minute));
    }
    
    sort(minute_table.begin(), minute_table.end());
    
    int curr_time = 540;
    int crew_cnt = 0;
    int seat_cnt = 0; //막차 자리 갯수
    int idx = 0;
    for(idx = 0; idx < minute_table.size(); idx++)
    {
        if(minute_table[idx] <= curr_time) {
            crew_cnt++;
            if(curr_time == last_time) seat_cnt++;
        }
        else {
            crew_cnt = 0;
            curr_time += t;
            idx--;
        }
        if(crew_cnt == m) {
            crew_cnt = 0;
            curr_time += t;
        }
        if(curr_time > last_time) break;
    }
    
    int corn_time = 0;
    if(idx < 0) corn_time = last_time;
    else if(curr_time > last_time) {
        if(seat_cnt < m) corn_time = last_time;
        else corn_time = minute_table[idx] - 1;
    }
    else {
        corn_time = last_time;
    }
    
    return getTime(corn_time);
}
