#include <stdio.h>
#include <string.h>
int main(){
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		char a[50];
		int sum=0;
		int x;
		scanf(" %s", a);

		for (int j=0; j<strlen(a); j++){
			x=(int)a[j] - 48;
			sum += x;
		}
		printf("%d\n", sum);
	}
}