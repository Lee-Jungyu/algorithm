#include <iostream>
using namespace std;

int T;

int main()
{
        scanf("%d", &T);
        while(T--)
        {
                int a, b;
                scanf("%d %d", &a, &b);
                int c = a % 10;
                int d = b % 4;
                if(d == 0)
                        d = b == 0 ? 0 : 4;
                
                int result = 1;
                for(int i = 0; i < d; i++)
                {
                        result *= c;
                        result = result % 10;
                }
                
                if(result == 0) result = 10;
                printf("%d\n", result);
        }
}
