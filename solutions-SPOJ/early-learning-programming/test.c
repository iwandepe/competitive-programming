#include <stdio.h>
int main(){
	int x;
	while (true){
		scanf("%d", &x);
		printf("%d\n", x);
		fflush(stdout);
		if (x==42)
			break;
	}
	return 0;
}