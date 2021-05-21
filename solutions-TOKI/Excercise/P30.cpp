#include <bits/stdc++.h>
using namespace std;

int maximum(int a, int b){
	return (a>b)? a: b;
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n,l,b,k,ver,hor;
		cin >>b>>k>>n>>l;

		// inisialisasi map dengan nilai 1
		int mp[201][201];
		for (ver=1; ver<=200; ver++)
			for (hor=1; hor<=200; hor++)
				mp[ver][hor]=1;
		
		// set map yang sudah ditempati dengan nilai 0
		for (int i=0; i<n; i++){
			int b1,k1,b2,k2;
			cin >>b1>>k1>>b2>>k2;
			for (ver=b1; ver<=b2; ver++){
				for (hor=k1; hor<=k2; hor++){
					mp[ver][hor] = 0; 
				}
			}
		}
		
		// buat map menjadi tabel kumulatif
		for (ver=1; ver<=b; ver++){
			for (hor=1; hor<=k; hor++){
				if (hor>1 && mp[ver][hor] && mp[ver][hor-1])
					mp[ver][hor] = mp[ver][hor-1]+1;
			}
		}

		/*
		Tabel sebelum dijadikan tabel kumulatif
		0 0 0 1 1 1 1 1 1 1 
		0 0 0 1 1 0 0 0 0 1
		0 0 0 1 1 1 1 1 1 1 
		0 0 0 1 0 0 0 0 1 1
		0 0 0 1 0 0 0 0 1 1
		1 1 1 1 0 0 0 0 1 1
		1 1 1 1 1 1 1 1 1 1
		1 0 0 0 1 1 1 1 1 1
		1 0 0 0 1 1 1 1 1 1
		1 1 0 0 0 0 0 0 0 0
		*/	

		/*
		Tabel setelah dijadikan tabel kumulatif
	0 0 0 1 2 3 4 5 6 7
	0 0 0 1 2 0 0 0 0 1
	0 0 0 1 2 3 4 5 6 7
	0 0 0 1 0 0 0 0 1 2
	0 0 0 1 0 0 0 0 1 2
	1 2 3 4 0 0 0 0 1 2
	1 2 3 4 5 6 7 8 9 10
	1 0 0 0 1 2 3 4 5 6
	1 0 0 0 1 2 3 4 5 6
	1 2 0 0 0 0 0 0 0 0
		*/	


		// Komputasi tiap petak dalam tabel dari kanan bawah ke kiri atas
		int max=0;
		for(hor=k; hor>=1; hor--){
			for (ver=b; ver>=1; ver--){
				if (!mp[ver][hor]) continue;
				
				int temp=mp[ver][hor];
				int min_length = temp;

				for (int v=ver-1; v>=1; v--){
					if (!mp[v][hor])
						break;

					if (mp[v][hor] < min_length){
						temp = temp+mp[v][hor]-(ver-v)*(min_length-mp[v][hor]);
						max = maximum(max, temp);
						min_length = mp[v][hor];
					}

					else{
						temp += min_length;
						max = maximum(max, temp);
					}
				}
			}
		}
		if (max>=l) cout << "YA" << endl;
		else cout << "TIDAK" <<endl;
	}
	return 0;
}