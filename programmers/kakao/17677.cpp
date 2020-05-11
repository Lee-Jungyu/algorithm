#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    map<string, int> mapA;
    map<string, int> mapB;
    map<string, int> mapC;
    map<string, int> mapD;
    int aCnt = 0;
    int bCnt = 0;
    
    
    for(int i = 0; i < str1.length() - 1; i++)
    {
        string s = "";
        char c1 = str1[i];
        char c2 = str1[i + 1];
        
        if(c1 >= 'a' && c1 <= 'z') c1 = c1 - 'a' + 'A';
        if(c2 >= 'a' && c2 <= 'z') c2 = c2 - 'a' + 'A';
        
        if(c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z')
        {
            s = s + c1 + c2;
        
            mapA[s]++;
            mapC[s]++;
        }
    }
    
    for(int i = 0; i < str2.length() - 1; i++)
    {
        string s = "";
        char c1 = str2[i];
        char c2 = str2[i + 1];
        
        if(c1 >= 'a' && c1 <= 'z') c1 = c1 - 'a' + 'A';
        if(c2 >= 'a' && c2 <= 'z') c2 = c2 - 'a' + 'A';
        
        if(c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z')
        {
            s = s + c1 + c2;
        
            mapB[s]++;
            mapC[s] = mapB[s] > mapC[s] ? mapB[s] : mapC[s];
        }
    }
    
    auto iterA = mapA.begin();
    auto iterB = mapB.begin();
    for(iterA = mapA.begin(); iterA != mapA.end(); iterA++)
    {
        for(iterB = mapB.begin(); iterB != mapB.end(); iterB++)
        {
            if(iterA->first == iterB->first) {
                string s = iterA->first;
                mapD[s] = mapA[s] < mapB[s] ? mapA[s] : mapB[s];
                break;
            }
        }
    }
    
    for(auto iter = mapC.begin(); iter != mapC.end(); iter++) {
        aCnt += iter->second;
    }
    
    for(auto iter = mapD.begin(); iter != mapD.end(); iter++) {
        bCnt += iter->second;
    }
    
    if(aCnt == 0) return 65536;
    
    double rate = bCnt * 1.0 / aCnt;
    int answer = rate * 65536;
    
    
    return answer;
}
