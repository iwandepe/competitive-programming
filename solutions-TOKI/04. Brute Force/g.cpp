#include <bits/stdc++.h>
using namespace std;


int i,j,k,l,ii,jj,kk,ll;

char arr[25][25], arr2[25][25];
bool visited[25][25];
int n,m;
int counter;

void func3(int x, int y){
	if (x>0 && x<m && y>=0 && y<n){
		if (arr2[x][y] == '.'){
			if (arr2[x-1][y] == '.')
				func3(x-1, y);
			while(arr2[x][y] == '.' && arr2[x-1][y] != '.'){
				arr2[x][y] = arr2[x-1][y];
				arr2[x-1][y] = '.';
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
			if (arr2[x][y] == c){
				counter += 1;
				visited[x][y]=true;
				arr2[x][y] = '.';
 				
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
			if (arr2[x][y] == c){
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
	int max=0;
	for (i=0; i<m; i++){
		for (j=0; j<n; j++) {
			
			// copy arr ke arr2 dan inisialisasi false visited
			for (k=0; k<m; k++){
				for (l=0; l<n; l++){
					arr2[k][l] = arr[k][l];
					visited[k][l] = false;
				}
			}
			
			// counter pencarian 1
			counter = 0;
			
			// pencarian satu
			func2(i, j, arr2[i][j]);
			
			// rangkaian bola yang dipilih harus lebih dari 1
			if (counter < 2) continue;
			
			// score sementara setelah pencarian pertama
			int score = counter*(counter-1);
			
			// peruntuhan
			for (k=0; k<n; k++)
				func3(m-1, k);
				
			// pencarian kedua
			int submax = 0;
			for (k=0; k<m; k++){
				for (l=0; l<n; l++){

					if (arr2[k][l]=='.') continue;
					
					// inisialisasi false visited
					for (kk=0; kk<m; kk++){
						for (ll=0; ll<n; ll++){
							visited[kk][ll] = false;
						}
					}
					
					counter = 0 ;
					func(k,l, arr2[k][l]);
					
					if (counter > submax){
						submax = counter;
					}
				}
			}
			
			// score akhir untuk satu elemen
			score += submax*(submax-1);
			
			if (score > max) 
				max = score;
		}
	}
	cout << max << endl;
	return 0;
}
