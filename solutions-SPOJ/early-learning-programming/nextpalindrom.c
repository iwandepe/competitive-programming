#include <stdio.h>
#include <string.h>
int main(){
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		int n;
		scanf("%d", &n);
		if (n==0){
			printf("1\n");
			continue;
		}
		while (1){
			n++;
			int polin=0;
			char str[10000000];
			sprintf(str, "%d", n);
			int lenght=strlen(str);
			while (str[0]=='0'){
				for (int j=0; j<lenght-1; j++){
					str[j]=str[j+1];
				}
				lenght--;
			}
			int k=lenght-1;
			for (int j=0; j<lenght/2; j++){
				if (str[j]!=str[k]){
					polin=1;
					break;
				}
				k--;
			}
			if (polin==0){
				printf("%d\n", n);
				break;
			}
		}
	}
}