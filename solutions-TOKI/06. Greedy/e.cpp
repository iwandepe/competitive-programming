#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a;
	
	// 1.	Input jumlah bebek dan jumlah sepatu yang tersedia
	cin>>n>>m;
	vector <int> v1,v2;
	
	// 2.	Input masing-masing ukuran bebek dan ukuran sepatu lalu masukkan ke vector
	for (int i=0; i<n; i++){
		cin >> a;
		v1.push_back(a);
	}
	for (int i=0; i<m; i++){
		cin >> a;
		v2.push_back(a);
	}
	
	// 3.	Urutkan kedua vektor itu secara ascending
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	// 4.	Looping sebanyak jumlah bebek dan cari sepatu yang sesuai 
	int sepatu = 0, jumlah = 0;
	for (int i=0; i<n; i++){
		for (int j=sepatu; j<m; j++){
			if (v1[i] == v2[j] || v1[i]+1 == v2[j]){
				jumlah++, sepatu++;
				break;
			}
			else if (v1[i]+1 < v2[j])
				break;
			sepatu++;
		}
	}
	cout << jumlah << endl;
	return 0;
}
