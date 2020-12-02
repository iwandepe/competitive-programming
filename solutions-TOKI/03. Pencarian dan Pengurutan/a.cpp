#include <bits/stdc++.h>
using namespace std;

// inisialisasi iterator
int i,j,k;
// inisialisasi vektor
vector <pair<int, int>> v;

int main()
{
	int n,murni;
	cin>>n>>murni;
	// loop untuk masukan sebanyak n
	for (i=0 ; i<n; i++){
		int a;
		cin >>a;
		int b = abs(murni-a);
		v.push_back(make_pair(b,a));
	}
	// sorting vektor dengan STL, otomatis sort
	// dari nilai pertama, jika sama dibandingkan nilai kedua
	sort(v.begin(), v.end());
	
	// output hasil
	cout << v[0].second << endl;
	return 0;
}
