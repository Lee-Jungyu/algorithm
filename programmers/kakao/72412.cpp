#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum Lang{
    CPP,
    JAVA,
    PYTHON
};

enum Job {
    BACK,
    FRONT
};

enum Career {
    JUNIOR,
    SENIOR
};

enum Food {
    CHICKEN,
    PIZZA
};

vector<int> info_score[3][2][2][2];
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    //info배열에서 info_score배열로 적절히 점수 push
    for(int i = 0; i < info.size(); i++) {
        int lang;
        int job;
        int career;
        int food;
        int score;
        
        if(info[i][0] == 'c') lang = CPP;
        if(info[i][0] == 'j') lang = JAVA;
        if(info[i][0] == 'p') lang = PYTHON;
        
        int chk_cnt = 0;
        for(int j = 0; j < info[i].length(); j++) {
            
            if(chk_cnt == 0 && info[i][j] == ' ') {
                if(info[i][j + 1] == 'b') job = BACK;
                if(info[i][j + 1] == 'f') job = FRONT;
                
                chk_cnt++;
                j++;
            }
            else if(chk_cnt == 1 && info[i][j] == ' ') {
                if(info[i][j + 1] == 'j') career = JUNIOR;
                if(info[i][j + 1] == 's') career = SENIOR;
                
                chk_cnt++;
                j++;
            }
            else if(chk_cnt == 2 && info[i][j] == ' ') {
                if(info[i][j + 1] == 'c') food = CHICKEN;
                if(info[i][j + 1] == 'p') food = PIZZA;
                
                chk_cnt++;
                j++;
            }
            else if(chk_cnt == 3 && info[i][j] == ' ') {
                string s = info[i].substr(j + 1, info[i].length() - j - 1);
                score = stoi(s);
                info_score[lang][job][career][food].push_back(score);
                
                chk_cnt++;
                j++;
            }
        }
    }
    
    //info_score의 각 배열을 모두 내림차순 정렬
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) {
                    sort(info_score[i][j][k][l].begin(), info_score[i][j][k][l].end());
                }
            }
        }
    }
    
    //query 진행
    for(int i = 0; i < query.size(); i++) {
        int lang = -1;
        int job = -1;
        int career = -1;
        int food = -1;
        int score = 0;
        
        if(query[i][0] == 'c') lang = CPP;
        if(query[i][0] == 'j') lang = JAVA;
        if(query[i][0] == 'p') lang = PYTHON;
        
        //query배열에서 단어 추출함
        int chk_cnt = 0;
        for(int j = 1; j < query[i].length(); j++) {
            if (chk_cnt == 0 && query[i][j] == ' ') {
                if(query[i][j + 5] == 'b') job = BACK;
                if(query[i][j + 5] == 'f') job = FRONT;
                chk_cnt++;
                j += 5;
            }
            else if (chk_cnt == 1 && query[i][j] == ' ') {
                if(query[i][j + 5] == 'j') career = JUNIOR;
                if(query[i][j + 5] == 's') career = SENIOR;
                chk_cnt++;
                j += 5;
            }
            else if (chk_cnt == 2 && query[i][j] == ' ') {
                if(query[i][j + 5] == 'c') food = CHICKEN;
                if(query[i][j + 5] == 'p') food = PIZZA;
                chk_cnt++;
                j += 5;
            }
            else if (chk_cnt == 3 && query[i][j] == ' ') {
                string s = query[i].substr(j + 1, query[i].length() - j - 1);
                score = stoi(s);
                chk_cnt++;
                j += 5;
            }
        }
        
        // 탐색 범위 설정
        int rangeLangA, rangeLangB;
        if(lang == -1) {
            rangeLangA = 0;
            rangeLangB = 2;
        }
        else {
            rangeLangA = rangeLangB = lang;
        }
        int rangeJobA, rangeJobB;
        if(job == -1) {
            rangeJobA = 0;
            rangeJobB = 1;
        }
        else {
            rangeJobA = rangeJobB = job;
        }
        int rangeCarA, rangeCarB;
        if(career == -1) {
            rangeCarA = 0;
            rangeCarB = 1;
        }
        else {
            rangeCarA = rangeCarB = career;
        }
        int rangeFoodA, rangeFoodB;
        if(food == -1) {
            rangeFoodA = 0;
            rangeFoodB = 1;
        }
        else {
            rangeFoodA = rangeFoodB = food;
        }
        
        // 설정된 탐색범위를 이용해 갯수 구함
        int sum = 0;
        for(int a = rangeLangA; a <= rangeLangB; a++) {
            for(int b = rangeJobA; b <= rangeJobB; b++) {
                for(int c = rangeCarA; c <= rangeCarB; c++) {
                    for(int d = rangeFoodA; d <= rangeFoodB; d++) {
                        if(info_score[a][b][c][d].size() == 0) continue;
                        
                        auto iter = lower_bound(
                            info_score[a][b][c][d].begin(),
                            info_score[a][b][c][d].end(),
                            score);
                        
                        if(iter != info_score[a][b][c][d].end()) {
                            sum += info_score[a][b][c][d].end() - iter;
                        }
                    }
                }
            }
        }
        
        answer.push_back(sum);
    }
    return answer;
}
