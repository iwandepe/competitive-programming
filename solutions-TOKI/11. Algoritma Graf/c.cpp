#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dijkstra(int s, int n);
int dist[201];
vector <pii> rumah[201];
int main()
{
    int n,m,q,u,v,w,result,before,after;
    cin >> n >> m >> q;
    while (m--)
    {
        cin >> u >> v >> w;
        rumah[u].push_back(make_pair(w, v));
        rumah[v].push_back(make_pair(w, u));
    }
    q--;
    result = 0;
    cin >> before;
    while(q--)
    {
        cin >> after;
        result += dijkstra(before, after);
        before = after;
    }
    cout << result << endl;
    return 0;
}

int dijkstra(int s, int after) {
    priority_queue <pii, vector <pii>, greater <pii> > pq;
    set <int> seen;
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        pii now = pq.top();
        pq.pop();
        if(seen.find(now.second) != seen.end())
        {
            continue;
        }
        seen.insert(now.second);
        for(int i = 0; i < rumah[now.second].size(); i++) {
            int next = rumah[now.second][i].second;
            int cost = rumah[now.second][i].first;

            if(now.first + cost < dist[next] || dist[next] == -1) {
                dist[next] = now.first + cost;
                pq.push({dist[next], next});
            }
        }
    }
    return dist[after];
}
