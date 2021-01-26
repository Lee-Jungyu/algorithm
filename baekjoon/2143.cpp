#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
vector<int> B;
vector<int> sum_A;
vector<int> sum_B;

int main()
{
    int n, m;
    long long int T, result = 0;

    cin >> T;

    // vector input
    cin >> n;
    A.push_back(0);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        A.push_back(A[i] + num);
    }

    cin >> m;
    B.push_back(0);
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        B.push_back(B[i] + num);
    }

    // make part sum
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int a = A[j] - A[i];
            sum_A.push_back(a);
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j <= m; j++) {
            int b = B[j] - B[i];
            sum_B.push_back(b);
        }
    }

    sort(sum_A.begin(), sum_A.end());
    sort(sum_B.begin(), sum_B.end());

    // two point
    int idx_A = 0, idx_B = sum_B.size() - 1;

    while(idx_A < sum_A.size() && idx_B >= 0) {
        int val_A = sum_A[idx_A];
        int val_B = sum_B[idx_B];
        long long cnt_A = 0;
        long long cnt_B = 0;

        if(val_A + val_B == T) {
            while(idx_A < sum_A.size() && sum_A[idx_A] == val_A) {
                idx_A++;
                cnt_A++;
            }
            while(idx_B >= 0 && sum_B[idx_B] == val_B) {
                idx_B--;
                cnt_B++;
            }

            result += cnt_A * cnt_B;
        }
        else if(val_A + val_B > T) {
            idx_B--;
        }
        else {
            idx_A++;
        }
    }

    cout << result << endl;

    return 0;
}
