#include <bits/stdc++.h>
using namespace std;

// inisialisasi iterator
int i,j,k;

// inisialisasi unordered map STL
unordered_map <string, string> umap;

int main()
{
	int n,q;
	cin >>n>>q;
	
	// loop masukan nama dan nomor
	// lalu insert ke unordered map
	while (n--){
		string name,num;
		cin >> name>>num;
		umap[name] = num;
	}
	
	// loop sebanyak perintah
	while (q--){
		string str;
		cin >> str;
		
		// jika nama ada di map outputkan nomornya
		if (umap.find(str) == umap.end())
			cout << "NIHIL" << endl;
			
		// jika tidak ada output NIHIL
		else
			cout << umap[str] << endl;
	}
	return 0;
}
