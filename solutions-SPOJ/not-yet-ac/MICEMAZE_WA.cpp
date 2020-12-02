#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

int i,j,k;

vector <pii> v[100005];
int dist[100005];

void dijkstra(int src, int n, int t) {
    priority_queue <pii, vector <pii>, greater <pii> > pq;
    set <int> seen;
    memset(dist, -1, sizeof(dist));
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        pii now = pq.top();
        pq.pop();
        if(seen.find(now.second) != seen.end()) continue;
        seen.insert(now.second);
        for(int i = 0; i < v[now.second].size(); i++) {
            int next = v[now.second][i].second;
            int cost = v[now.second][i].first;

            if(now.first + cost < dist[next] || dist[next] == -1) {
                dist[next] = now.first + cost;
                pq.push({dist[next], next});
            }
        }
    }
    int count = 0;
    for (i=1; i<=n; i++)
    	if (dist[i] <= t)
    		count ++;
    		
    cout << count << endl;
    return;
}

int main()
{
	int n,e,t,m;
	cin >> n >> e >> t >> m;
	for (i=0; i<m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		v[b].pb(mp(c,a));
	}
	int count = 0;
	dijkstra(e,n,t);
	return 0;
}
