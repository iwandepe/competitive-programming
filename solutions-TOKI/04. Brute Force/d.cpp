#include <bits/stdc++.h>
using namespace std;

vector <int> all_score;
int n, x, r, y, j, d[10], combination[10], idx[10];
char t[10];

bool meyakinkan(int a[], int x){
	for (int i=0; i<x; i++)
		if (t[combination[i]] == 'Y')
			return true;
	return false;
}

void permute(int a[], int l, int r)  
{  
    if (l == r){
//    	for (int i=0; i<=r; i++)
//    		cout << a[i] << " ";
//    	cout << endl;
    	int score = 0;
    	int temp = '0';
    	for (int i=0; i<=r; i++){
    		if (temp == 'P')
				score += d[combination[i]]*2;
			else if (temp == 'L')
				score += d[combination[i]]/2;
			else 
				score += d[combination[i]];

			if (meyakinkan(combination, i))
				score += y;
			temp = t[combination[i]];
		}
	    all_score.push_back(score);
	}
    else
    {  
        for (int i = l; i <= r; i++)  
        {   
            swap(a[l], a[i]); 
            permute(a, l+1, r);  
            swap(a[l], a[i]);
        }  
    }  
}  

int temp_index = 0;

void combine (int offset, int k){
	if (k == 0) {
 		permute(combination, 0, r-1);
		cout << endl;
    	return;
  	}
  	for (int i = offset; i <= n - k; ++i) {
    	combination[temp_index] = idx[i];
    	temp_index++;
	
		combine(i+1, k-1);
		
    	combination[temp_index] = -1;
    	temp_index--;
 	}
}

int binarySearch(int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
        if (all_score[m] == x){
			while (true){
				m--;
				if (m == -1)
					return m+1;
				if (all_score[m] > x)
					return m+1;
			}
		}
  
        if (all_score[m] > x) 
            l = m + 1; 
   
        else
            r = m - 1; 
    } 
	return r+1;
} 

int main(){
	string subsoal;
	
	cin >> subsoal >> x;
	cin >> n >> r >> y >> j;
	
	for (int i=0; i<n; i++){
		cin >> d[i] >> t[i];
		idx[i] = i;
	}
	
	combine(0, r);
	sort(all_score.begin(), all_score.end(), greater<int>());
	
	for (int i=0; i<j; i++){
		int out = 0, h;
		cin >> h;
		cout << binarySearch(0, all_score.size()-1, h) << endl;
	}
	return 0;
}

		
