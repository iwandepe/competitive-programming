#include <bits/stdc++.h>
using namespace std;

// inisialisasi iterator
int i,j,k;

// inisialisasi vektor dengan 2 nilai
// <int> untuk jumlah huruf, <string> untuk namanya
vector <pair<int, string>> v;
int main()
{
	int n;
	cin>>n;
	
	// loop masukan sebanyak n dan push back ke vektor
	for (i=0 ; i<n; i++){
		string s;
		cin >>s;
		int a=s.length();
		v.push_back(make_pair(a,s));
	}
	
	// sorting vektor dengan sort() STL
	// otomatis mengurutkan vektor berdasarkan nilai pertama yaitu <int> jumlah huruf dalam nama
	// lalu jika sama akan diurutkan berdasarkan nilai kedua yaitu <string> nama sesuai alphabet
	sort(v.begin(), v.end());
	
	// output isi vektor yang telah diurutkan
	for (i=0;i<n;i++)
		cout << v[i].second << endl;
	return 0;
}
