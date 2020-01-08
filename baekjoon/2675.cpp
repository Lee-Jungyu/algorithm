#include <stdio.h>
#include <string.h>

int main(){
	int t, i, j, k, n, length;

	char str[30] = " ";
	scanf("%d", &t);

	for(i = 0; i < t; i++){
		scanf("%d%s", &n, str);
		length = strlen(str);
    
		for(j = 0; j < length; j++){
			for(k = 0; k < n; k++){
				putchar(str[j]);
			}
		}
    
		puts("");
	}
}
