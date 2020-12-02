#include <stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		double a,b;
		scanf("%lf%lf", &a, &b);
		printf("%lf\n", a+b);
	}
}