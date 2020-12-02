// wrong answer

#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	for (int k=0; k<t; k++){
		int n, digit=0,save;
		int bil[200];
		bil[0] = 1;
		scanf("%d", &n);
		if (n==0)
			printf("0\n");
		else{
			for (int i=n; i>=1; i--){
				save=0;
				for (int j=0; j<=digit; j++){
					save=bil[j]*i+save;
					bil[j]=save%10;
					save=save/10;
				}
				while (save>0){
					bil[++digit]=save%10;
					save/=10;
				}
			}
			for (int i=digit; i>=0; i--)
				printf("%d", bil[i]);
			printf("\n");
		}
	}
}