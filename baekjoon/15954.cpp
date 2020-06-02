#include <stdio.h>
#include <math.h>
int arr[500];
int main()
{
    int N, K;
    double result = 10000000.0;
    scanf("%d %d", &N, &K);
    
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    while(K <= N) 
    {
        for(int i = 0; i <= N - K; i++)
        {
            int sum = 0;
            for(int j = i; j < i + K; j++) {
                sum += arr[j];
            }
            double m = sum * 1.0 / K;
            
            double sum2 = 0.0;
            for(int j = i; j < i + K; j++) {
                sum2 += pow(arr[j] - m, 2);
            }
            double v = sum2 * 1.0 / K;
            double a = sqrt(v);

            if(a < result) result = a;
        }

        K++;
    }

    printf("%.11f\n", result);
}
