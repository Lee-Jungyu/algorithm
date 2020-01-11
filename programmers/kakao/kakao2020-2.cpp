#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool checkRightString(string str)
{
	int l = 0, r = 0;

	for (int i = 0; i < str.length(); i++)
	{
        if(str[i] == '(') l++;
        else r++;
        
		if (l - r < 0) {
            return false;
        }
	}
	return true;
}

string solution(string p) {
	if (p == "") return p;

	int l = 0;
	int r = 0;

	if (p[0] == '(') l++;
	else r++;

	string u = "";
	string v = "";

    u += p[0];
	int i;
	for (i = 1; i < p.length(); i++)
	{
		if (l - r == 0) break;

		u += p[i];
		if (p[i] == '(') l++;
		else r++;
	}
    
	v = p.substr(i, p.length() - i);
	string answer = "";
	if (checkRightString(u)) {
		u += solution(v);
		return u;
	}
	else {
		answer += '(';
		answer += solution(v);
		answer += ')';
        
        if(u.length() > 2) {
		    u = u.substr(1, u.length() - 2);
        }
        else {
            u = "";
        }
		for (int i = 0; i < u.length(); i++)
		{
			if (u[i] == '(') u[i] = ')';
			else u[i] = '(';
		}
		answer += u;
	}
	return answer;
}
