#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string word, vector<string> pages) {
    int answer = 0;
    map<string, int> url_hash; //match url with number
    vector<pair<double, double>> point_vector(pages.size()); //basic point, link point
    vector<vector<string>> link_vector(pages.size()); // link with n th page
    
    
    for(int i = 0; i < word.length(); i++) {
        if(word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] - 'A' + 'a';
        }
    }
    
    for(int i = 0; i < pages.size(); i++) {
        for(int j = 0; j < pages[i].length(); j++) {
            if(pages[i][j] >= 'A' && pages[i][j] <= 'Z') {
                pages[i][j] = pages[i][j] - 'A' + 'a';
            }
        }
    }
    
    for(int i = 0; i < pages.size(); i++) {
        //word counting
        int word_cnt = 0;
        for(int j = 0; j < pages[i].length() - word.length(); j++) {
            if(pages[i][j] == word[0]) {
                if((pages[i][j - 1] >= 'a' && pages[i][j - 1] <= 'z') || (pages[i][j + word.length()] >= 'a' && pages[i][j + word.length()] <= 'z')) continue;
                bool word_check = true;
                for(int k = 0; k < word.length(); k++) {
                    if(pages[i][j + k] != word[k]) {
                        word_check = false;
                        break;
                    }
                }
                if(word_check) word_cnt++;
            }
        }
        
        // extract url
        int url_start_pos = pages[i].find("<meta property=\"og:url\" content=\"");
        pages[i] = pages[i].substr(url_start_pos + 33, pages[i].length() - url_start_pos - 34);
        int url_end_pose = pages[i].find("\"");
        string url = pages[i].substr(0, url_end_pose);
        url_hash[url] = i + 1;
        
        // extract alink
        int link_cnt = 0;
        while(pages[i].find("<a href=") != string::npos) {
            int link_start_pose = pages[i].find("<a href=");
            pages[i] = pages[i].substr(link_start_pose + 9, pages[i].length() - 10);
            int link_end_pose = pages[i].find("\"");
            string link = pages[i].substr(0, link_end_pose);
            
            link_vector[i].push_back(link);
            link_cnt++;
        }
        
        point_vector[i] = make_pair(word_cnt, word_cnt * 1.0 / link_cnt);
    }
    
    for(int i = 0; i < pages.size(); i++) {
        for(int j = 0 ; j < link_vector[i].size(); j++) {
            if(url_hash[link_vector[i][j]] != 0)
                point_vector[url_hash[link_vector[i][j]] - 1].first += point_vector[i].second;
        }
    }
    
    int max_idx = 0;
    double max_total_point = 0.0;
    for(int i = 0; i < pages.size(); i++) {
        if(point_vector[i].first > max_total_point) {
            max_total_point = point_vector[i].first;
            max_idx = i;
        }
    }
    
    return max_idx;
}
