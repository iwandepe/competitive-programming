#include <bits/stdc++.h>
using namespace std;

int i,j,k;

char arr[25][25];
bool visited[25][25];
int n,m;
int counter = 0;

void func3(int x, int y){
	if (x>0 && x<m && y>=0 && y<n){
		if (arr[x][y] == '.'){
			if (arr[x-1][y] == '.')
				func3(x-1, y);
			while(arr[x][y] == '.' && arr[x-1][y] != '.'){
				arr[x][y] = arr[x-1][y];
				arr[x-1][y] = '.';
				func3(x-1,y);
			}
		}
		else
			func3(x-1, y);	
	}
}

void func2(int x, int y, char c){
	if (x>=0 && x<m && y>=0 && y<n){
		if (!visited[x][y]){
			if (arr[x][y] == c){
				counter += 1;
				visited[x][y]=true;
				arr[x][y] = '.';
 				
				func2(x+1, y,c);
				func2(x-1, y,c);
				func2(x, y+1,c);
				func2(x, y-1,c);
			}
		}
	}
}

void func(int x, int y, char c){
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
	int xmax,ymax;
	int max=0;
	for (i=0; i<m; i++){
		for (j=0; j<n; j++) {
			counter =0;
			func(i,j,arr[i][j]);
			if (counter > max) 
				max = counter, xmax=i, ymax=j;
		}
	}
	for (i=0; i<m; i++){
		for (j=0; j< n; j++){
			visited[i][j] = false;
		}
	}
	
	func2(xmax, ymax, arr[xmax][ymax]);
	for (j=0; j<n; j++){
		func3(m-1, j);
	}
	for (i=0; i<m; i++){
		for (j=0; j<n; j++){
			if (j>0) cout << " ";
			cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}
