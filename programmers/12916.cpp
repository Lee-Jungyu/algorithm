#include <string>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int py = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'p' || s[i] == 'P') py++;
        else if(s[i] == 'y' || s[i] == 'Y') py--;
    }
    
    return !py;
}
