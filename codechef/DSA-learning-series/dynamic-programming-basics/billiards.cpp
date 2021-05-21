#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 1000000009;

int main() {
	ll t;
	cin>>t;
	ll dp[1000001];
	dp[0]=1;
	dp[1]=0;
	dp[2]=1;
	for(ll i=3;i<=1000000;i++){
		dp[i]=(dp[i-2]+dp[i-3])%MOD;
	}
	while(t--){
		int x;
		cin>>x;	
		cout<<dp[x]<<endl;
	}
	return 0;
}
