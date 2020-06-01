#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> hash_map;
    
    int idx_no = 0;
    for(idx_no = 1; idx_no <= 26; idx_no++) {
        string str = "";
        str += (char)('A' + idx_no - 1);
        hash_map[str] = idx_no;
    }
    
    for(int i = 0; i < msg.length();)
    {
        string str = "";
        str += msg[i];
        string tmp = "";
        int j = 0;
        for(j = 1; hash_map[str]; j++) {
            tmp = str;
            str += msg[i + j];
        }
        answer.push_back(hash_map[tmp]);
        hash_map[str] = idx_no++;
        
        i += j - 1;
    }
    
    return answer;
}
