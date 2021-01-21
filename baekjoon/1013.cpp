#include <string>
#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--) {
        string str;
        cin >> str;

        bool type;
        bool pre_type;
        // 100+1+ 일 경우 type = 1, 01+ 일 경우 type = 0;
        if(str[0] == '0') {
            type = 0;
            pre_type = 1;
        }
        else {
            type = 1;
            pre_type = 0;
        }

        bool check = true;
        bool first_one = true;
        bool first_zero = true;
        bool type_finish = false;

        if(str.length() == 1) check = false;

        for(int i = 1; i < str.length(); i++) {
            if(!type) {
                if(str[i - 1] == '0') {
                    if(str[i] == '0') {
                        check = false;
                        break;
                    }
                    if(str[i] == '1') {
                        type_finish = true;
                    }
                }
                else {
                    type_finish = false;
                    if(str[i] == '1') {
                        pre_type = type;
                        type = 1;
                        first_one = true;
                    }
                }
            }
            else {
                if(str[i - 1] == '1') {
                    if(str[i] == '1') {
                        if(first_one && type != pre_type) {
                            check = false;
                            break;
                        }
                    }
                    else {
                        type_finish = false;
                        if(first_one) {
                            first_one = false;
                            first_zero = true;
                        }
                        else {
                            if(i < str.length() - 1) {
                                if(str[i + 1] == '1') {
                                    type = 0;
                                }
                            }
                            if(str[i - 2] == '0') {
                                type = 0;
                            }
                        }
                    }
                }
                else {
                    if(str[i] == '1') {
                        if(first_zero) {
                            check = false;
                            break;
                        }
                        else {
                            pre_type = type;
                            type_finish = true;
                        }
                    }
                    else {
                        if(first_zero) {
                            first_zero = false;
                        }
                    }
                }
            }
        }

        if(check && type_finish) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
