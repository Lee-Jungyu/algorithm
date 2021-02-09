#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int sum = 0;
    int num = 0;
    bool check = false;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '-' || str[i] == '+') {
            if(!check) {
                sum += num;
                if(str[i] == '-')
                    check = true;
            }
            else {
                sum -= num;
            }
            num = 0;
        }
        else {
            num *= 10;
            num += (str[i] - '0');
        }
    }

    if(!check) sum += num;
    else sum -= num;

    cout << sum << '\n';
}
