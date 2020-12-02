#include <stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		int n,div=0;
		scanf("%d", &n);
		for (int j=1; j<n/2+1; j++){
			if (n%j == 0)
				div+=j;
		}
		printf("%d\n", div);
	}
}