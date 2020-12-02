#include <bits/stdc++.h>
using namespace std;

// inisialisasi vektor
vector <double> v;
int main()
{
	int n,k;
	cin>>n>>k;
	// loop masukan sebanyak n lalu push back ke vektor
	while(n--){
		int a;
		cin >>a;
		v.push_back(a);
	}
	// sorting vektor dengan sort() STL
	sort(v.begin(), v.end());
	
	// output tinggi badan bebek terpendek ke-k
	cout << v[k-1] << endl;
	return 0;
}
