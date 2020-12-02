#include <bits/stdc++.h>
using namespace std;

// inisialisasi iterator
int i,j,k;

// inisialisasi vektor
vector <double> v;
int main()
{
	int n;
	cin >>n;
	
	// loop masukan sebanyak n dan push back ke vektor
	for(i=0; i<n; i++){
		double a;
		cin >> a;
		v.push_back(a);	
	}
	
	// mengurutkan isi vektor
	sort(v.begin(), v.end());
	
	// jika jumlah genap maka median = rata-rata dua nilai tengah
	if (n%2==0)
		printf("%.1f\n", (v[n/2-1]+v[n/2])/2);
		
	// jika ganjil
	else 
		printf("%.1f\n", v[n/2]);
	return 0;
}
