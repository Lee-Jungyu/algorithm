#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char> char_vector;
vector<bool> check_vowel;

void dfs(string str, int size, int cnt, int idx, int con, int vow) {
    
    cnt++;
    str += char_vector[idx];
    if(check_vowel[idx]) vow++;
    else con++;

    if(size == cnt) {
        if(con >= 2 && vow >= 1)
            cout << str << endl;
        return;
    }

    for(int i = idx + 1; i < char_vector.size(); i++) {
        dfs(str, size, cnt, i, con, vow);
    }
}

int main()
{
    int L, C;
    cin >> L >> C;

    for(int i = 0; i < C; i++) {
        char c;
        cin >> c;
        char_vector.push_back(c);
    }

    sort(char_vector.begin() , char_vector.end());

    for(int i = 0; i < char_vector.size(); i++) {
        if(char_vector[i] == 'a' || char_vector[i] == 'e' || char_vector[i] == 'i' || char_vector[i] == 'o' || char_vector[i] == 'u') {
                check_vowel.push_back(true);
        }
        else {
            check_vowel.push_back(false);
        }
    }

    for(int i = 0; i < C - L + 1; i++) {
        string str = "";
        dfs(str, L, 0, i, 0, 0);
    }
}
