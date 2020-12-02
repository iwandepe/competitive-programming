#include <bits/stdc++.h>
using namespace std;

const int maximum =2005;

unordered_map <char, int> umap;
int result=0;

int mecs(string X, string Y, int n, int m)
{
	int dp[n+1][m+1];
	int i,j;
	
	for (i=0; i<=n; i++){
		for (j=0; j<=m; j++){
			if (i==0 || j==0)
				dp[i][j] =0;
			else if (X[i-1] == Y[j-1])
				dp[i][j] = dp[i-1][j-1] + umap[X[i-1]];
			else	
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][m];
}

int main()
{
	int n,m;
	cin>>n>>m;
	char c[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	for (int i=0; i<26; i++){
		int v;
		cin>>v;
		umap[c[i]]=v;
	}
	string x,y;
	cin>>x>>y;
	cout << mecs(x,y,n,m) << endl;
	return 0;
}
