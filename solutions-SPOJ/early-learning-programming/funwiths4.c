#include <stdio.h>
int main(){
	int n,y;
	scanf("%d%d", &n, &y);
	int s[n], q[n];
	for (int i=0; i<n; i++)
		scanf("%d", &s[i]);
	for (int i=0; i<n; i++)
		scanf("%d", &q[i]);
	if (y>=0){
		int qp=y;
		int cek=1;
		for (int i=0; i<n; i++){
			if (s[i]==q[qp])
				printf("%d ", i+1);
			if (qp==n-1)
				cek=-1;
			qp+=cek;
		}
	}
}