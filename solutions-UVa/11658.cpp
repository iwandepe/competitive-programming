#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	
	// input
	// jika bertemu dengan input 0 0 maka program berhenti
	while ((cin >> n >> x)&&(!((n==0)&&(x==0))))
	{
		if (n==0) break;
		x--;
		
		// inisialisasi array saham dan dynamic programming
		int stocks[n];
		bool dp[10005];
		
		// set tabel dp menjadi false
		memset(dp, false, sizeof(dp));
		
		// input porsi saham dan kali dengan 100 untuk menjadikan integer
		for (int i=0; i<n; i++){
			int p,q;
			scanf("%d.%d", &p, &q);
			p = p*100+q;
			stocks[i] = p;
		}
		
		// tabel dp pada saham target bernilai true
		// karena saham target pasti ikut di dalam koalisi yang dicari
		int stockx = stocks[x];
		dp[stockx] = true;
		
		// iterasi harga saham yang ada
		for (int i=0; i<n; i++){
			if (i==x) continue;
			
			// iterasi pada dp
			for (int j=10000; j>=stocks[i]; j--){
				if (dp[j-stocks[i]]){
					dp[j] = true;
				}
			}
		}
		
		// untuk mencari profit maksimum 
		// iterasi dari 5001 sampai ketemu nilai dp[] true
		for (int i=5001; i<=10000; i++){
			if (dp[i]){
				printf("%.2lf\n", 100.0 * ((double)stockx / (double)i));
				break;
			}
		}
	}
	return 0;
}
