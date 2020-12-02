#include <stdio.h>
#include <math.h>
int main(){
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++){
		int n, to;
		double max=0;
		scanf("%d", &n);
		for (int j=1; j<=n; j++){
			double x,y;
			scanf("%lf%lf", &x, &y);
			double jauh=sqrt(x*x + y*y);
			if (jauh>max){
				max=jauh;
				to=j;
			}

		}
		printf("Case %d: %d\n", i,to);
	}
}