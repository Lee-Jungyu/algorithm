#include <stdio.h>
int main()
{
    int x, y;
    scanf("%d \n%d", &x, &y);
    if(x > 0) {
        printf("%d\n", y > 0 ? 1 : 4);
    }
    else {
        printf("%d\n", y > 0 ? 2 : 3);
    }        
}
