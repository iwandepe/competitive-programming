#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	// looping sebanyak kasus uji
	while (t--)
	{
		int price, n, max=1000000;
		cin >> price;
		cin >> n;
		
		// inisialisasi dynamic programming untuk menimpan proses yang sudah dilakuakn
		// inisialisasi koin untuk menyimpan koin yang dimiliki
		// inisialisasi jumlah untuk menyimpan jumlah koin minimum yang menghasilkan nomimal tertentu
		bool dp[10001];
		int koin[100], jumlah[10001];
		
		// set false ke table dp
		memset(dp, false, sizeof(dp));
		
		// set dp[0] true karena tidak membutuhkan koin sama sekali untuk memperoleh nominal uang 0
		// set jumlah[0] = 0 karena tidak membutuhkan koin sama sekali untuk memperoleh nominal uang 0
		dp[0] = true;
		jumlah[0] = 0;
		
		// input koin yang dimiliki
		for (int i=0; i<n; i++)
			cin >> koin[i];
		
		// set jumlah ke infinity
		for (int i=1; i<10001; i++)
			jumlah[i] = 1000000000;
		
		// looping sebanyak koin
		for (int i=0; i<n; i++){
			
			// looping pada dp
			for (int j=10000; j>=koin[i]; j--){
				if (dp[j-koin[i]]){
					dp[j] = true;
					
					// mencari jumlah minimum
					jumlah[j] = min(jumlah[j], jumlah[j-koin[i]]+1);
				}
			}
		}
		
		// untuk mencari nominal bayar minimal
		// iterasi mulai dari harga barang sampai ketemu dp[] = true
		for (int i=price; i<10001; i++){
			if (dp[i]){
				cout << i << " " << jumlah[i] << endl;
				break;
			}
		}
		
	}
	return 0;
}
