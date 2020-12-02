#include <stdio.h>

int main()
{
	int n,m;
	scanf("%d", &n);
	int arr[n];
	for (int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &m);
	int arr2[m];
	for (int i=0; i<m; i++){
		scanf("%d", &arr2[i]);
		if (arr[i]==arr2[i])
			printf("%d ", i+1);
	}
	// printf("\b\n");

	return 0;
}