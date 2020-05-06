#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> genre_cnt_map;
    for(int i = 0; i < genres.size(); i++)
    {
        genre_cnt_map[genres.at(i)] += plays.at(i);
    }
    
    vector<pair<string, int>> temp_vector;
    map<string, int>::iterator iter;
    for(iter = genre_cnt_map.begin(); iter != genre_cnt_map.end(); iter++)
        temp_vector.push_back(make_pair(iter->first, iter->second));
    
    sort(temp_vector.begin(), temp_vector.end(), cmp);
    
    for(int i = 0; i < temp_vector.size(); i++)
    {
        int song1 = 0, song2 = 0, flag = 0;
        for(int j = 0; j < genres.size(); j++)
        {
            if(temp_vector.at(i).first == genres[j]) {
                if(flag == 0) {
                    song1 = j;
                    flag++;
                }
                else if(flag == 1) {
                    if(plays[j] > plays[song1]) {
                        song2 = song1;
                        song1 = j;
                    }
                    else {
                        song2 = j;
                    }
                    flag++;
                }
                else {
                    if(plays[j] > plays[song1]) {
                        song2  = song1;
                        song1 = j;
                    }
                    else if(plays[j] > plays[song2]) {
                        song2 = j;
                    }
                }
            }
        }
        if(flag > 0)
            answer.push_back(song1);
        if(flag > 1)
            answer.push_back(song2);
    }
    
    return answer;
}
