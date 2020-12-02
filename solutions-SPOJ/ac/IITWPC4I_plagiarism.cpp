#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll milkman[100005], visited[100005];
vector<pll> road[100005];

int main()
{
	ll t,n,m,i,j;
	cin >> t;
	while (t--)
	{	
		priority_queue <pll> pq;
		
		cin >> n >> m;
		for (i=1; i<=n; i++)
			cin >> milkman[i], visited[i]=0, road[i].clear();

		for (i=0; i<m; i++){
			int u,v,c;
			cin >> u >> v >> c;
			road[u].push_back(make_pair(c,v));
			road[v].push_back(make_pair(c,u));
		}
		
		for (i=1; i<=n; i++){
			if (milkman[i]){
				visited[i] = 1;
				for (j=0; j<road[i].size(); j++)
					pq.push(make_pair(-road[i][j].first, road[i][j].second));
			}
		}
		
		
		ll res = 0;
		while (!pq.empty()){
			pll now = pq.top();
			pq.pop();
			if (!visited[now.second]){
				visited[now.second] = 1;
				res += -now.first;
				for (j=0; j<road[now.second].size(); j++)
					pq.push(make_pair(-road[now.second][j].first, road[now.second][j].second));
			}
		}
		
		ll flag = 0;
		for (i=1; i<=n; i++)
			if (visited[i] == 0){
				flag = true;
				break;
			}
				
		if (flag) cout << "impossible" << endl;
		else cout << res << endl;
	}
	return 0;
}
