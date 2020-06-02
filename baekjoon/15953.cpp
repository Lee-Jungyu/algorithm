#include <stdio.h>
int main()
{
    int T;
    int a_prize[7] = {0, 500, 300, 200, 50, 30, 10};
    int b_prize[6] = {0, 512, 256, 128, 64, 32};
    scanf("%d", &T);
    while(T--) {
        int a, b, sum = 0;
        scanf("%d %d", &a, &b);

        if(a != 0) {
            int prize = 0;
            for(int i = 0; i < a; i += prize)
                prize++;
                
            if(prize <= 6)
                sum += a_prize[prize];
        }
        if(b != 0) {
            int prize = 1;
            int tmp = 1;
            for(int i = 1; i < b; i += tmp) {
                prize++;
                tmp *= 2;
            }
            
            if(prize <= 5)
                sum += b_prize[prize];
        }
        printf("%d\n", sum * 10000);
    }
}
