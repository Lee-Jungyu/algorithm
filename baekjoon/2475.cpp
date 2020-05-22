#include <stdio.h>
int main()
{
    int n, sum = 0;
    for(int i = 0; i < 5; scanf("%d", &n), sum += n*n, i++);
    printf("%d\n", sum % 10);
}
