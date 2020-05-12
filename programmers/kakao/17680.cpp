#include <string>
#include <vector>

using namespace std;

string toLowerCase(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    if(cacheSize == 0) {
        return 5 * cities.size();
    }
    
    for(int i = 0; i < cities.size(); i++)
    {
        string city = toLowerCase(cities[i]);
        if(cacheSize > cache.size()) {
            int j = 0;
            for(j = 0; j < cache.size(); j++) {
                if(cache[j] == city) {
                    cache.erase(cache.begin() + j);
                    cache.push_back(city);
                    answer += 1;
                    break;
                }
            }
            if(j == cache.size()) {
                cache.push_back(city);
                answer += 5;
            }
        }
        else {
            int j = 0;
            for(j = 0; j < cache.size(); j++) {
                if(cache[j] == city) {
                    cache.erase(cache.begin() + j);
                    cache.push_back(city);
                    answer += 1;
                    break;
                }
            }
            if(j == cache.size()) {
                cache.erase(cache.begin());
                cache.push_back(city);
                answer += 5;
            }
        }
    }
    
    return answer;
}
