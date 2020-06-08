#include <stdio.h>
#include <vector>
using namespace std;

bool non_prime_number[2000001] = {false, };
vector<long long int> prime_numbers;
int main()
{
    int T;
    scanf("%d", &T);

    for(long long int i = 2; i < 2000001 ;i++) {
        if(non_prime_number[i]) continue;
        prime_numbers.push_back(i);
        for(long long int j = i * 2; j < 2000001; j += i) {
            non_prime_number[j] = true;
        }
    }

    while(T--) {
        long long int A, B, sum;
        scanf("%lld %lld", &A, &B);

        sum = A + B;
        
        
        if(sum < 4) {
            printf("NO\n");
            continue;
        }
        if(sum % 2 == 0) {
            printf("YES\n"); //4이상의 짝수는 두 소수의 합으로 나타낼 수 있을 것이다.
            continue;
        }
        sum -= 2; //항상 짝수 + 홀수만 홀수가 되고 짝수 중 소수인 것은 2밖에 없다.

        bool flag = false;
        for(int i = 0; i < prime_numbers.size() && prime_numbers[i] < sum; i++) {
            if(sum % prime_numbers[i] == 0) {
                flag = true;
                break;
            }
        }

        if(flag) printf("NO\n");
        else printf("YES\n");
    }
}
