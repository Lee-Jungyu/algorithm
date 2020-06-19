#include <stdio.h>
#include <algorithm>
int A[100001];

int main()
{
    int N, M, t;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &t);
        A[i] = t;
    }

    std::sort(A, A + N);

    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d", &t);

        int left = 0;
        int right = N - 1;
        int answer = 0;
        while(left <= right) {
            int middle = (left + right) / 2;

            if(A[middle] == t) {
                answer = 1;
                break;
            }

            if(A[middle] < t) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }

        printf("%d\n", answer);
    }
}
//이분탐색
