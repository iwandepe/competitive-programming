#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin >> n;
    // inisialisasi vektor
    vector <string> vec;
    
    // loop sebanyak n
    while (n--)
    {
        string str;
        cin >> str;
        // push back nama bebek yang baru datang ke vektor
        vec.push_back(str);
        
        // sorting lagi setiap ada bebek yang baru datang untuk meng-update urutan dalam vektor
        sort(vec.begin(), vec.end());
        
        // cari nama bebek yang baru datang tersebut dalam vektor dengan pencarian biasa
        // looping sebanyak isi vektor, jika ketemu nama yang dicari lalu outputkan indexnya
        for (i=0; i<vec.size(); i++)
            if (vec[i]==str)
                cout << i+1 << endl;
    }
    return 0;
}
