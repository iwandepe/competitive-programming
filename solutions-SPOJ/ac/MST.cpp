#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

typedef long long ll;

ll i,j,k;

struct graph{
	ll src, dst, w;
};

graph edge[100005];
ll par[100005];

ll find(int x) {
    if(par[x] != x) 
        par[x]=par[par[x]], x=par[x];
	return x;
} 

void Kruskal(ll m) {
    ll res = 0;
    for(i = 0; i < m; i++) {
        ll src = edge[i].src;
        ll dst = edge[i].dst;
        ll w = edge[i].w;
        ll parSrc = find(src);
        ll parDst = find(dst);

        if(parSrc != parDst) {
            res += w;
            par[parSrc] = par[parDst];
        }
    }
    cout << res << endl;
    return;
}

bool compare(graph a, graph b)
{
	if (a.w < b.w)
		return true;
	return false;
}

int main()
{
	ll n,m;
	cin >> n >> m;
	for (i=1;i<=n; i++)
		par[i] = i;
	for (i=0; i<m; i++){
		ll a,b,c;
		cin >> edge[i].src >> edge[i].dst >> edge[i].w;
	}
	sort(edge, edge+m, compare);
	Kruskal(m);
	return 0;
}
