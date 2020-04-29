#include <iostream>
using namespace std;

int T;

int main()
{
        scanf("%d", &T);
        while(T--)  {
                int sum = 0, x1, x2, y1, y2, n, cx, cy, r;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                scanf("%d", &n);
                for(int i = 0; i < n; i++) {
                        scanf("%d %d %d", &cx, &cy, &r);

                        int dist1 = (cx - x1)*(cx - x1) + (cy - y1)*(cy - y1);
                        int dist2 = (cx - x2)*(cx - x2) + (cy - y2)*(cy - y2);

                        int check1 = dist1 < r*r ? 1 : 0;
                        int check2 = dist2 < r*r ? 1 : 0;

                        if(check1 != check2)
                                sum += 1;
                        
                }
                printf("%d\n", sum);
        }

}
