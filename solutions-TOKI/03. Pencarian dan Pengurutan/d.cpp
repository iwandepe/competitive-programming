#include <bits/stdc++.h>
using namespace std;

// inisialisasi iterator
int i,j,k;

// inisialisasi vektor
vector <int> v;

int main()
{
	int n;
	cin >>n;
	
	// loop masukan sebanyak n dan push back ke vektor
	while (n--){
		int a;
		cin >> a;
		v.push_back(a);
	}
	int q;
	cin >> q;
	
	// loop sebanyak perintah
	while (q--){
		int min,max;
		cin >> min>>max;
		// outputkan jumlah elemen yang memiliki nilai diatas min dan di bawah max
		// menggunakan upper bound STL vektor
		cout<<upper_bound(v.begin(), v.end(),max)-upper_bound(v.begin(),v.end(),min)<<endl;
	}
	
	return 0;
}
