#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i = 0; i < phone_book.size(); i++)
    {
        for(int j = 0; j < phone_book.size(); j++)
        {
            if(phone_book.at(i).size() == phone_book.at(j).size())
                continue;
            
            if(phone_book.at(i).size() > phone_book.at(j).size())
            {
                if(phone_book.at(j) == phone_book.at(i).substr(0, phone_book.at(j).size()))
                    return false;
            }
        }
    }
    return answer;
}
