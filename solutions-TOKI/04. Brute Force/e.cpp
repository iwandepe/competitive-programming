#include <bits/stdc++.h>
using namespace std;

int i,j,k;

int arr[25][25];
bool visited[25][25];
int n,m;
int counter = 0;

void func(int x, int y, int c){
	if (x>=0 && x<m && y>=0 && y<n){
		if (!visited[x][y]){
			if (arr[x][y] == c){
				counter += 1;
				visited[x][y]=true;
				func(x+1, y,c);
				func(x-1, y,c);
				func(x, y+1,c);
				func(x, y-1,c);
			}
		}
	}
}

int main(){
	cin >> m>>n;
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			cin >> arr[i][j];
			visited[i][j]=false;
		}
	}
	int x,y;
	int max=0;
	for (i=0; i<m; i++){
		for (j=0; j<n; j++) {
			counter =0;
			func(i,j,arr[i][j]);
			if (counter > max) 
				max = counter;
		}
	}
	counter = max;
	cout << counter*(counter-1) << endl;
	return 0;
}
