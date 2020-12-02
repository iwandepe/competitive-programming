#include <stdio.h>
#include <math.h>
int main(){
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		int n,j=0,bil=2;
		scanf("%d", &n);
		while (j<n){
			int apoint=0;
			int a[3];
			int p=0;
			int hasil;
			while (p<3){
				int prima=0;
				for (int k=2; k<=sqrt(bil); k++){
					if (bil%k == 0){
						prima=1;
						break;
					}
				}
				if (prima==0){
					a[apoint]=bil;
					apoint++;
					p++;
				}
				bil++;
			}
			hasil=(a[0]*a[1])+a[2];
			printf("%d ", hasil);
			j++;
		}
		printf("\n");
	}
}