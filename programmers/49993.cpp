#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> char_hash;
    
    for(char c = 'A'; c <= 'Z'; c++) {
        char_hash[c] = 0;
    }
    
    for(int i = 0; i < skill.length(); i++) {
        char_hash[skill[i]] = i + 1;
    }
    
    for(int i = 0; i < skill_trees.size(); i++) {
        int tmp = 1;
        bool valid = true;
        for(int j = 0; j < skill_trees[i].length(); j++) {
            int num = char_hash[skill_trees[i][j]];
            if(num != 0 && num != tmp) {
                valid = false;
                break;
            }
            else if(num == tmp) {
                tmp++;
            }
        }
        if(valid) answer++;
    }
    return answer;
}
