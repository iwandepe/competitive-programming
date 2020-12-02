// wrong answer
// maksud soal tidak jelas

#include <stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		int a,b,c;
		scanf("%d%d%d", &a,&b,&c);

		if (a>=c){
			if (a==c){
				if (c%b == 0)
					printf("%d\n", c/b);
				else if (b<c)
					printf("%d\n", c/b+1);
				else 
					printf("1\n");
			}
			else if (c%b == 0)
				printf("%d\n", c/b);
			else if (b<c)
				printf("%d\n", c/b+1);
			else
				printf("1\n");
		}
		else if (b>=c){
			if (b==c){
				if (c%a == 0)
					printf("%d\n", c/a);
				else if (a<c)
					printf("%d\n", a/b-1);
				else
					printf("1\n");
			}
			else if (c%a == 0)
				printf("%d\n", c/a);
			else if (a<c)
				printf("%d\n", c/a+1);
			else
				printf("1\n");
		}
		else
			printf("-1\n");
	}
}