// how to scan string including space

#include <stdio.h>
#include <string.h>
int main(){
	int l;
	scanf("%d", &l);
	char s[l];
	scanf(" %s", s);
	int n;
	scanf("%d", &n);
	for (int i=0; i<=n; i++){
		if (i>0){
			char str[1000];
			fgets(str, 1000, stdin);
			printf("%s\n", str);
			// for (int j=0; j<strlen(str); j++){
			// 	for (int k=0; k<n; k++){
			// 		if (str[j]==s[k]){
			// 			if (k==n-1)
			// 				str[j]=s[0];
			// 			else
			// 				str[j]=s[k+1];

			// 		}
			// 	}
			// }
			// for (int j=0; j<strlen(str); j++){
			// 	printf("%c", str[j]);
			// 	str[j]='\0';
			// }
			// printf("\n");
		}
	}
}