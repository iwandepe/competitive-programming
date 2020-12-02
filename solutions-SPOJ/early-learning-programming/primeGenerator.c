#include <stdio.h>
#include <math.h>
main(){
	long long t, a, b, x;
	scanf("%d", &t);
	for (int i=0;i<t;i++){
		scanf("%lld %lld", &a, &b);
		for (int j=a;j<=b;j++){
			x=0;
			for (int k=2;k<=sqrt(j);k++){
				if (j%k==0){
                    x++;
                    break;
				}
			}
			if (j!=1 && x==0) printf("%lld\n", j);
		}
	}
}
