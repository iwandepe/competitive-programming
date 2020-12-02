// lanjut nanti

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void tambah(char a[], char b[]){
	printf(" %s\n", a);
	printf("+%s\n", b);
	for (int i=0; i<=strlen[a]; i++)
		printf("-");
	printf("\n");
	int hasil[501];
	int save;
}

void kurang(char a[], char b[])

void kali(char a[], char b[])

int main(){
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		char str[10001];
		char a[500],b[500];
		scanf(" %s", str);
		i=0;
		while (str[i]>='0' && str[i]<='9'){
			a[i]=str[i]
			i++;
		}
		strcpy(b, str[i+1], strlen(a));
		if (str[i]=='+')
			tambah(a,b);
		else if (str[i]=='-')
			kurang(a,b);
		else if (str[i]=='*')
			kali(a,b);
	}
}