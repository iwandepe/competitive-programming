#include <stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		int a,b,c,d;
		scanf("%d%d%d%d", &a,&b,&c,&d);
		int p=d-c+1;
		int q=d+c-1;
		for (int j=1; j<=a; j++){
			for (int k=1; k<=b; k++){
				if (k==q || k==p)
					printf("*");
				else
					printf(".");
			}
			p++;
			q--;
			printf("\n");
		}
	}

}