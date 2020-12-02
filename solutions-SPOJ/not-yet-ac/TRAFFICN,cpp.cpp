/*
WA somewhere, i dont know
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define pii pair<int, int>
#define pipii pair<int, pair<int,int> >

int i,j,k;

vector <pii> v[10005], vv[10005];
int dist[10005][2];

void dijkstra(int src, int dst, int n) {
    priority_queue <pipii, vector <pipii>, greater <pipii> > pq;
//    set <int> seen;
    for (i=1; i<=n; i++) dist[i][0] = -1, dist[i][1] = -1;
    dist[src][0] = 0;
    pq.push({0, {0, src}});
    while(!pq.empty()) {
        pipii now = pq.top();
        int f,c,d;
        f = now.first;
        c = now.second.first;
        d = now.second.second;
        pq.pop();
//        if(seen.find(d) != seen.end()) continue;
//        seen.insert(d);
        for(i = 0; i < v[d].size(); i++) {
            int next = v[d][i].second;
            int cost = v[d][i].first;

            if(c + cost < dist[next][f] || dist[next][f] == -1) {
                dist[next][f] = c + cost;
                pq.push({f,{dist[next][f], next}});
            }
        }
        if (f==1) continue;
        for (i=0; i<vv[d].size(); i++) {
        	int next = vv[d][i].second;
        	int cost = vv[d][i].first;
        	
        	if(c + cost < dist[next][1] || dist[next][1] == -1){
        		dist[next][1] = c + cost;
        		pq.push({f,{dist[next][1], next}});
			}
		}
    }
}

int main()
{
	int dataset;
	cin >> dataset;
	while (dataset--)
	{
		int n,m,k,s,t;
		cin >>n>>m>>k>>s>>t;
		for (i=1;i<=m;i++){
			int a,b,c;
			cin >>a>>b>>c;
			v[a].pb(mp(c,b));
		}
		for (i=1;i<=k;i++){
			int a,b,c;
			cin >>a>>b>>c;
			vv[a].pb(mp(c,b));
			vv[b].pb(mp(c,a));
		}
		dijkstra(s,t,n);
		
		int d1,d2;
		d1 = dist[t][0];
		d2 = dist[t][1];
		
		if (d1==-1 && d2==-1) cout << "-1";
		else if(d1==-1) cout << d2;
		else if(d2==-1) cout << d1;
		else if(d1 < d2) cout << d1;
		else cout << d2;
		cout << endl;
		
		for (i=1; i<=n; i++)
			v[i].clear(), vv[i].clear();
	}
	return 0;
}
