#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		int m,n,a,b;
		scanf("%d%d%d%d", &m,&n,&a,&b);
		for (int j=1; j<=m; j++){
			for (int k=1; k<=n; k++){
				if (j==a || k==b)
					printf("*");
				else
					printf(".");
			}
			printf("\n");
		}
	}
}