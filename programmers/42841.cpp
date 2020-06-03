#include <string>
#include <vector>

using namespace std;

bool check_valid_number(int n)
{
    bool check[10] = {false,};
    
    while(n) {
        if(n % 10 == 0) return false;
        if(check[n % 10]) return false;
        check[n % 10] = true;
        n /= 10;
    }
    
    return true;
}

pair<int, int> check_score(int n, int m)
{
    pair<int, int> p;
    
    int flag[10] = {0, };
    int strike = 0;
    int ball = 0;
    while(n) {
        int a = n % 10;
        int b = m % 10;
        
        flag[a]++;
        flag[b]++;
        
        if(a == b) strike++;
        
        n /= 10;
        m /= 10;
    }
    
    for(int i = 1; i < 10; i++) {
        if(flag[i] == 2) ball++;
    }
    ball -= strike;
    
    p.first = strike;
    p.second = ball;
    
    return p;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    for(int i = 123; i <= 987; i++)
    {
        if(!check_valid_number(i)) continue;
        
        int j = 0;
        for(j = 0; j < baseball.size(); j++)
        {
            pair<int, int> p = check_score(i, baseball[j][0]);
            if(p.first != baseball[j][1] || p.second != baseball[j][2]) break;
        }
        
        if(j == baseball.size()) answer++;
    }
    
    return answer;
}
