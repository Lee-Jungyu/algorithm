#include <string>
#include <vector>

using namespace std;

int fibo[2001];
int MOD = 1234567;

long long solution(int n) {
    long long answer = 0;
    
    fibo[1] = 1;
    fibo[2] = 2;
    
    for(int i = 3; i <= n; i++) 
        fibo[i] = (fibo[i - 1] % MOD + fibo[i - 2] % MOD) % MOD;
    
    
    return fibo[n];
}
