#include <bits/stdc++.h>
using namespace std;

struct peserta {
 string id;
 int tes1, tes2, tes3;
} peserta[85];

int main(){
	int t,n,m;
	cin >> t;
	for (int i=0; i<t; i++){
		cin >> n >> m;
		string id;
		cin >> id;
		for (int j=0; j<n; j++){
			cin >> peserta[j].id >> peserta[j].tes1 >> peserta[j].tes2 >> peserta[j].tes3;
		}
		for (int j=0; j<n-1; j++){
			if (peserta[j].tes3 < peserta[j+1].tes3){
				swap(peserta[j], peserta[j+1]);
			}
			else if (peserta[j].tes3 == peserta[j+1].tes3){
				if (peserta[j].tes2 < peserta[j+1].tes2){
					swap(peserta[j], peserta[j+1]);
				}
				else if(peserta[j].tes2 == peserta[j+1].tes2){
					if (peserta[j].tes1 < peserta[j+1].tes1){
						swap(peserta[j], peserta[j+1]);
					}
				}
			}
		}
		bool flag = true;
		for (int j=0; j<m; j++){
			if(peserta[j].id == id){
				cout << "YA" << endl;
				flag = false;
			}
		}
		if (flag){
			cout << "TIDAK" << endl;
		}
	}
}
