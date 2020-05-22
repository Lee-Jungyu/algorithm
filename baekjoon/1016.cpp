#include <stdio.h>
using namespace std;

bool check[1000001];
int main()
{
    long long min_value, max_value;
    scanf("%ld %ld", &min_value, &max_value);

    int answer = max_value - min_value + 1;

    for(long long i = 2; i * i <= max_value; i++) {
        long long start;
        if(min_value % (i * i)) { start = i * i - (min_value % (i * i)); }
        else start = 0;

        for(long long j = start; j <= max_value - min_value; j += i*i) {
            if(!check[j]) {
                answer -= 1;
                check[j] = true;
            }
        }
    }

    printf("%d", answer);
}
