#include <bits/stdc++.h>
using namespace std;

// inisialisasi iterator
int i,j,k;

int main()
{
	int n,m,k; 
	cin >>n>>m>>k;
	
	// inisialisai petak 2D
	int petak[n+1][m+1];
	// loop masukan sebanyak petak yaitu n*m
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
			cin >> petak[i][j];
	
	// buat flag untuk menandai jika sudah ketemu jawaban
	bool flag = false;
	// loop dari kolom terkecil dahulu, lallu loop baris
	// j untuk kolom, i untuk baris
	for (j=1; j<=m; j++){
		for (i=1; i<=n; i++){
			int menarik;
			
			// jika petak cuma satu maka nilainya nol
			if (m==1 && n==1){
				menarik = 0;
			}
			
			// jika petak hanya terdiri satu kolom 
			else if (m==1){
				if (i==1){
					menarik = petak[i+1][j];
				}
				else if (i==n){
					menarik = petak[i-1][j];
				}
				else{
					menarik = petak[i-1][j]*petak[i+1][j];
				}
			}
			
			// jika petak hanya terdiri satu baris
			else if (n==1){
				if (j==1){
					menarik = petak[i][j+1];
				}
				else if (j==m){
					menarik = petak[i][j-1];
				}
				else{
					menarik = petak[i][j+1]*petak[i][j-1];
				}
			}
			
			// selanjutnya jika petak berupa banyak kolom dan banyak baris
			else if (j==1){
				if (i==1){
					menarik = petak[i+1][j]*petak[i][j+1];
				}
				else if (i==n){
					menarik = petak[i-1][j]*petak[i][j+1];
				}
				else{
					menarik = petak[i-1][j]*petak[i+1][j]*petak[i][j+1];
				}
			}
			else if (j==m){
				if (i==1){
					menarik = petak[i+1][j]*petak[i][j-1];
				}
				else if (i==n) {
					menarik = petak[i-1][j]*petak[i][j-1];
				}
				else{
					menarik = petak[i+1][j]*petak[i-1][j]*petak[i][j-1];
				}
			}
			else{
				if (i==1){
					menarik = petak[i+1][j]*petak[i][j-1]*petak[i][j+1];
				}
				else if (i==n){
					menarik = petak[i-1][j]*petak[i][j-1]*petak[i][j+1];
				}
				else{
					menarik = petak[i-1][j]*petak[i+1][j]*petak[i][j+1]*petak[i][j-1];
				}
			}
			
			// jika perhitungan sudah sama dengan yang dicari langsung break
			if (menarik == k){
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	
	//outputkan baris kolom pada posisi terakhir dalam loop
	if (flag) 
		cout << i << " " << j << endl;
	else 
		cout << "0 0" <<endl; 
	
	return 0;
}
