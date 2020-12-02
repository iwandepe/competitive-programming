#include <stdio.h>
#include <string.h>
int main(){
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		char str[100000];
		scanf(" %s", str);
		char ptr[3] = {'c', 'b', 'a'};
		int len = strlen(str), point = 1;
		if (len == 1){
            printf("a\n");
            continue;
		}
		int bisa=0;
		for (int j=0; j<len; j++){
            if (str[j] == '?'){
                for (int k=0; k<3; k++){
                    if (ptr[k] != str[j-1] && ptr[k] != str[j+1])
                        str[j] = ptr[k];
                }
            }
            else{
                if (str[j] == str[j+1]){
                    bisa = 1;
                    printf("-1\n");
                    break; break;
                }
            }
		}
		if (bisa == 0)
            printf("%s\n", str);
	}
}
