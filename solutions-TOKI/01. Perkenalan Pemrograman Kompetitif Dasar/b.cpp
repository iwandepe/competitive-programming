#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main(){
	int R, C;
	scanf("%d%d", &R, &C);
	char arr[25][10];
	for (int i=0; i<R; i++) {
		scanf("%s", arr[i]);
	}
	int bottom = R-1;
	while (1) {
		bool isDone = true;
		for (int i=R-1; i>=0; i--) {
			bool isCollapse = true;
			for (int j=0; j<C; j++) 
				if (arr[i][j] == '0') 
					isCollapse = false;

			if (isCollapse) {
				for (int k=0; k<C; k++) 
					arr[i][k] = '0';

				if (isDone) {
					isDone = false;
					bottom = i;
				}
			}
		}
		if (!isDone){
			for (int i=bottom-1; i>=0; i--) {
				for (int j=0; j<C; j++) {
					if (arr[i][j] == '0')
						continue;

					int iterDown = i;
					while (iterDown < R-1 && arr[iterDown+1][j] == '0') 
						iterDown++;

					swap(arr[i][j], arr[iterDown][j]);
				}
			}
		} else {
			break;
		}
	}

	for (int i=0; i<R; i++) {
		printf("%s\n", arr[i]);
	}
	return 0;
}
