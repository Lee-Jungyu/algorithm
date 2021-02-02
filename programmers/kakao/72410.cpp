#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    
    string tmp = "";
    for(int i = 0; i < new_id.length(); i++) {
        if(new_id[i] >= 'a' && new_id[i] <= 'z')
            tmp += new_id[i];
        else if(new_id[i] >= 'A' && new_id[i] <= 'Z')
            tmp += new_id[i] + 'a' - 'A';
        else if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            tmp += new_id[i];
        else if(new_id[i] >= '0' && new_id[i] <= '9')
            tmp += new_id[i];
    }
    
    string result = "";
    bool check = false;
    for(int i = 0; i < tmp.length(); i++) {
        if(!check) {
            result += tmp[i];
            if(tmp[i] == '.') check = true;
        }
        else {
            if(tmp[i] != '.') {
                check = false;
                result += tmp[i];
            }
        }
    }
    
    if(result[0] == '.') result = result.substr(1, result.length() - 1);
    if(result[result.length() - 1] == '.') result = result.substr(0, result.length() - 1);
    if(result.length() == 0) result = "a";
    if(result.length() > 15) result = result.substr(0, 15);
    if(result[result.length() - 1] == '.') result = result.substr(0, result.length() - 1);
    
    if(result.length() < 3) {
        while(result.length() != 3) {
            result += result[result.length() - 1];
        }
    }
    
    return result;
}
