#include <bits/stdc++.h>
using namespace std;

// inisialisasi iterator
int i,j,k;

// inisialisasi struct untuk menampung
// berat total karung beras, harga total, dan harga per unit
struct Beras{
	double w,c;
	double cpu; // harga perunit
};

// fungsi untuk sorting struct menurut harga per unit
bool compare(struct Beras a, struct Beras b){
	return a.cpu > b.cpu;
}

int main()
{
	int n,x;
	cin >>n>>x;
	// inisialisasi array of struct
	struct Beras beras[n];
	
	// loop masukan berat karung beras
	for (i=0;i<n;i++){
		cin >> beras[i].w;
	}
	// loop masukan harga total dan menghitung harga per unit
	for (i=0;i<n;i++){
		cin>> beras[i].c;
		beras[i].cpu = beras[i].c/beras[i].w;
	}
	// sorting array of struct beras sesuai dengan fungsi modifikasi
	sort(beras,beras+n,compare);
	
	int index=0;
	double m_cost=0;
	// loop menghitung harga maksimal
	while (x>0 && index<n){
		if (x <= beras[index].w){
			m_cost += beras[index].cpu*x;
			x = 0;
		}
		else{
			m_cost += beras[index].c;
			x -= beras[index].w;
		}
		index++;
	}
	// output hasil
	printf("%.5lf\n", m_cost);
	return 0;
}
