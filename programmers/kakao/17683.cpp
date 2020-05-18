#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int toInteger(string str)
{
    int result = 0;
    
    for(int i = 0; i < str.length(); i++)
    {
        result *= 10;
        int n = str[i] - '0';
        result += n;
    }
    
    return result;
}

class Music
{
public:
    int runtime = 0;
    string title = "";
    string melody = "";
    string info = "";
    
    Music() {}
    Music (string info) {this->info = info;}
    
    void initMusic()
    {
        int startTime, lastTime;
        startTime = toInteger(info.substr(0, 2)) * 60 + toInteger(info.substr(3, 2));
        lastTime = toInteger(info.substr(6, 2)) * 60 + toInteger(info.substr(9, 2));
        runtime = lastTime - startTime;
        
        string lastInfo = info.substr(12, info.length() - 12);
        
        bool flag = false;
        
        for(int i = 0; i < lastInfo.length(); i++)
        {
            if(lastInfo[i] == ',') {
                flag = true;
                continue;
            }
            
            if(!flag) {
                title += lastInfo[i];
            }
            else {
                melody += lastInfo[i];
            }
        }
    }
    
    bool checkMelody(string str) {
        string temp_melody = "";
        string temp_melody2 = "";
        
        int len = runtime;
        int idxCheck = -1;
        for(int i = 0; i < len; i++)
        {
            if(melody[i % melody.length()] == '#') {
                temp_melody[temp_melody.length() - 1] = temp_melody[temp_melody.length() - 1] - 'A' + 'a';
                len++;
            }
            else {
                temp_melody += melody[i % melody.length()];
            }
            idxCheck = i;
        }
        
        if(melody[(idxCheck + 1) % melody.length()] == '#') {
            temp_melody[temp_melody.length() - 1] = temp_melody[temp_melody.length() - 1] - 'A' + 'a';
        }
        
        int len2 = str.length();
        for(int i = 0; i < len2; i++) {
            if(str[i] == '#') {
                temp_melody2[temp_melody2.length() - 1] = temp_melody2[temp_melody2.length() - 1] - 'A' + 'a';
            }
            else {
                temp_melody2 += str[i];
            }
        }
        
        int ii = temp_melody.length() - temp_melody2.length() + 1;
        for(int i = 0; i < ii; i++) {
            if(temp_melody[i] == temp_melody2[0]) {
                bool flag = true;
                for(int j = 0; j < temp_melody2.length(); j++) {
                    if(temp_melody[i+j] != temp_melody2[j]) {
                        flag = false;
                        break;
                    }
                }
                
                if(flag) return true;
            }
        }
        
        return false;
    }
};

string solution(string m, vector<string> musicinfos) {
    
    int longest = 0;
    string title = "(None)";
    for(int i = 0; i < musicinfos.size(); i++)
    {
        Music music;
        music.info = musicinfos[i];
        music.initMusic();
        if(music.checkMelody(m)) {
            if(longest < music.runtime) {
                longest = music.runtime;
                title = music.title;
            }
        }
    }
    
    return title;
}
