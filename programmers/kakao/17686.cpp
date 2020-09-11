#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class File {
public:
    string name;
    string head;
    int number;
    
    File() {}
    File(string name) {
        this->name = name;
        
        int idx;
        //find head
        for(idx = 0; idx < name.length(); idx++) {
            if(name[idx] >= '0' && name[idx] <= '9') break;
        }
        head = name.substr(0, idx);
        for(int i = 0; i < head.length(); i++) {
            if(head[i] >= 'A' && head[i] <='Z') head[i] = head[i] - 'A' + 'a';
        }
        
        //find number
        number = 0;
        int number_idx = idx;
        for(;idx < name.length(); idx++) {
            if(name[idx] < '0' || name[idx] > '9') break;
            if(idx - number_idx == 5) break;
        }
        string number_string = name.substr(number_idx, idx - number_idx);
        
        for(number_idx = 0; number_idx < number_string.length(); number_idx++) {
            number *= 10;
            number += number_string[number_idx] - '0';
        }
        
    }
};

bool cmp(File a, File b) {
    if(a.head == b.head) return a.number < b.number;
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> f_vector;
    
    for(int i = 0; i < files.size(); i++) {
        File f(files[i]);
        f_vector.push_back(f);
    }
    
    stable_sort(f_vector.begin(), f_vector.end(), cmp);
    
    for(int i = 0; i < files.size(); i++) {
        answer.push_back(f_vector[i].name);
    }
    
    return answer;
}
