#include <bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long n,b,h;
	vector <int> v;
	cin >>n>>b;
	for (int i=0; i<n; i++){
		cin>>h;
		v.push_back(h);
	}
	sort(v.begin(), v.end(), greater<int>());
	int s=0;
	for (int i=0; i<n; i++){
		s+=v[i];
		if (s>=b){
			cout << i+1 << endl;
			break;
		}
	}
	return 0;
}
