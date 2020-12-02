#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,a;
	
	// 1.	Input jumlah dimensi vektor
	cin>>n;
	vector <long long> v1,v2;
	
	// 2.	Input besaran kedua vektor dan push back ke dalam STL vector
	for (int i=0; i<n; i++){
		cin >> a;
		v1.push_back(a);
	}
	for (int i=0; i<n; i++){
		cin >> a;
		v2.push_back(a);
	}
	
	// 3.	Urutkan kedua vector tersebut (vector pertama secara ascending dan vector kedua secara descending)
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), greater<int>());
	
	// 4.	Kalikan tiap nilai dalam vektor tersebut dan jumlahkan hasilnya ke variable hasil
	long long s=0;
	for (int i=0; i<n; i++){
		s+=v1[i]*v2[i];
	}
	cout << s << endl;
	return 0;
}
