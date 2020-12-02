#include <stdio.h>
#include <math.h>

int faktorial (int n){
    if (n==0) return 1;
	return (n*faktorial(n-1));
}

main(){
	int n, out;
	scanf("%d", &n);
	out = faktorial(n)+pow(2,n)-n;
	printf("%d\n", out);
}
