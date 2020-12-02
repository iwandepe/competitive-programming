#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

int i,j,k;

vector <pii> v[10005];
int dist[10005];
map <string, int> msi;
map <int, string> mis;

void dijkstra(int src, int dst) {
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
	cout << dist[dst] << endl;
    return;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int idx=1; idx<=n; idx++)
		{
			string name;
			cin >> name;
			msi[name] = idx;
			int p;
			cin >> p;
			while (p--)
			{
				int dst, cost;
				cin >> dst >> cost;
				v[idx].pb(mp(cost,dst));
				v[dst].pb(mp(cost,idx));
			}
		}
		int r;
		cin >> r;
		while (r--)
		{
			string src, dst;
			cin >> src >> dst;
			dijkstra(msi[src], msi[dst]);
		}
		for (i=1;i<=n;i++) v[i].clear();	
	}
	return 0;
}
