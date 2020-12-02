#include <stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		int n,x,y;
		scanf("%d%d%d", &n,&x,&y);
		for (int j=2; j<n; j++){
			if (j%x==0 && j%y!=0)
				printf("%d ", j);
		}
		printf("\n");
	}
}