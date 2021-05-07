#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> referral_map;
map<string, int> profit_map;


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    // 트리 부모 설정
    for(int i = 0; i < enroll.size(); i++) {
        referral_map[enroll[i]] = referral[i];
    }
    
    // 판매자 수익 계산
    for(int i = 0; i < seller.size(); i++) {
        int money = amount[i] * 100;
        string name = seller[i];
        while(referral_map.find(name) != referral_map.end()) {
            profit_map[name] += money - money / 10;
            money = money / 10;
            
            name = referral_map[name];
        }
    }
    
    // 판매금 배열에 등록
    for(int i = 0; i < enroll.size(); i++) {
        answer.push_back(profit_map[enroll[i]]);
    }
    
    return answer;
}
