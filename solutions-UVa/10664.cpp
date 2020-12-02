	#include <bits/stdc++.h>
using namespace std;

int arr[25];
int dp[120][25];
int n;

int compute(int w, int c) 
{ 
    if (dp[w][n] != -1) return dp[w][n];
    
    int mx = 0, t;
    for (int i=c; i<n; i++){
    	if (arr[i] <= w){
	    	t = arr[i] + compute(w-arr[i], i+1);
	    	if (mx < t) mx = t;
		}
	}
	
	dp[w][c] = mx; 
    return dp[w][c]; 
} 

int main(){
	int t;
	cin>>t;
	getchar();
	while (t--){
		string line;
		getline(cin, line);
		stringstream stream(line);
		n=0;
		int x;
		int total = 0;
		while (stream >> x){
			arr[n] = x;
			total += arr[n];
			n++;
		}
		
		memset(dp, -1, sizeof(dp));
		
		if (total%2==1) cout << "NO" << endl;
		else if (compute(total/2, 0) == total/2)	cout << "YES" << endl;
		else cout <<  "NO" << endl;
	}
	return 0;
}
