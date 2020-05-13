#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> temp; 
    map<string, string> recordmap;
    
    for(int i = 0; i < record.size(); i++) {
        string id = "";
        bool emptyFlag = false;
        int id_start_idx = 0;
        int id_last_idx = 0;
        for(int j = 0; j < record[i].length(); j++) {
            if(!emptyFlag &&record[i][j] == ' ') {
                id_start_idx = j + 1;
                emptyFlag = true;
            }
            else if(emptyFlag && record[i][j] == ' ') {
                id_last_idx = j - 1;
                break;
            }
        }
        
        id = record[i].substr(id_start_idx, id_last_idx - id_start_idx + 1);
        
        if(record[i][0] == 'E') {
            //Enter
            string nn = "";
            for(int j = record[i].length() - 1; j >= 0; j--) {
                if(record[i][j] == ' ') break;
                nn = record[i][j] + nn;
            }
            
            temp.push_back(make_pair("Enter", id));
            recordmap[id] = nn;
        }
        else if (record[i][0] == 'L') {
            //Leave
            temp.push_back(make_pair("Leave", id));
        }
        else {
            //Change
            string nn = "";
            for(int j = record[i].length() - 1; j >= 0; j--) {
                if(record[i][j] == ' ') break;
                nn = record[i][j] + nn;
            }
            
            recordmap[id] = nn;
        }
    }
    
    for(int i = 0; i <temp.size(); i++) {
        string str = "";
        if(temp[i].first == "Enter") {
            str = recordmap[temp[i].second] + "님이 들어왔습니다.";
        }
        else {
            str = recordmap[temp[i].second] + "님이 나갔습니다.";
        }
        answer.push_back(str);
    }
    return answer;
}
