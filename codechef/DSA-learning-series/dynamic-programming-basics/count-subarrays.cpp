// AC 8/03/2021 19:58

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ll arr[n],dp[n],result;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		dp[0]=1, result=1;
		for(int i=1;i<n;i++){
			if (arr[i-1]<=arr[i])
				dp[i]=dp[i-1]+1;
			else
				dp[i]=1;
			result+=dp[i];
		}
		cout<<result<<endl;
	}
	return 0;
}
