#include <stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		int n,g=1,s=1,b=1,count=0,first=0;
		scanf("%d", &n);
		int arr[n];
		for (int j=0; j<n; j++){
			scanf("%d", &arr[j]);
		}
		while (count<n){
			printf("count=%d\n", count);
			if (arr[count]==arr[count+1]){
				g++; count++;
			}
			else{
				count++; break;
			}
		}
		printf("g=%d\n", g);
		while (count<n){
			printf("count=%d\n", count);
			if (arr[count]==arr[count+1]){
				s++; count++;
			}
			else{
				if (s>g){
					count++; break;
				}
				else{
					s++; count++;
				}
			}
		}
		printf("s=%d\n", s);
		while (count<n){
			printf("count=%d\n", count);
			if (arr[count]==arr[count+1]){
				b++; count++;
			}
			else{
				if (b>g){
					count++; break;
				}
				else{
					b++; count++;
				}
			}
		}
		printf("b=%d\n", b);
		if (count <= n/2)
			printf("g=%d s=%d b=%d\n", g, s, b);
		else
			printf("0 0 0\n");
	}
}