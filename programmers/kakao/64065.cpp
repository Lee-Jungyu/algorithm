#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int str2int(string s)
{
    int a = 0;
    for(int i = 0; i < s.length(); i++)
    {
        a += s[i] - '0';
        if(i != s.length() - 1) a *= 10;
    }

    return a;
}

vector<int> solution(string s) {
    vector<int> answer;

    map<int, int> arr;

    string str = "";
    int tmp = 0;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] != '{' && s[i] != '}')
        {
            str += s[i];
        }
    }

    string nstr = "";
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ',') {
            int num = str2int(nstr);
            arr[num]++;
            nstr = "";
            continue;
        }

        nstr += str[i];
    }

    int num = str2int(nstr);
    arr[num]++;

    vector<pair<int, int>> temp_vector;
    map<int, int>::iterator iter;

    for(iter = arr.begin(); iter != arr.end(); iter++)
        temp_vector.push_back(make_pair(iter->first, iter->second));

    sort(temp_vector.begin(), temp_vector.end(), cmp);

    for(int i = 0; i < temp_vector.size(); i++)
    {
        answer.push_back(temp_vector[i].first);
    }

    return answer;
}
