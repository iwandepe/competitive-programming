// wrong answer

#include <stdio.h>
#include <math.h>
int main(){
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		int x1,y1,r1,x2,y2,r2;
		scanf("%d%d%d%d%d%d", &x1,&y1,&r1,&x2,&y2,&r2);
		int s = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

		if (s==r1 || s==r2)
			printf("E\n");
		else if (s<r1+r2){
			if (r1>r2){
				if (x1+r1>x2+r2 && y1+r1>y2+r2 && x1-r1<x2-r2 && y1-r1<y2-r2)
					printf("I\n");
				else
					printf("O\n");
			}
			else{
				if (x2+r2>x1+r1 && y2+r2>y1+r1 && x2-r2<x1-r1 && y2-r2<y1-r1)
					printf("I\n");
				else
					printf("O\n");
			}
		}
		else
			printf("O\n");
	}
}