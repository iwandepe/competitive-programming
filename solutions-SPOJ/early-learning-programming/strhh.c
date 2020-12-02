#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		char str[200];
		scanf(" %s", str);
		for (int j=0; j<strlen(str)/2; j+=2)
			printf("%c", str[j]);
		printf("\n");
	}
}
