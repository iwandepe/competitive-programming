#include <bits/stdc++.h>
using namespace std;
#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",&t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int V = 2000;
int i,j,k;

VI G[V];

bool isBipartiteUtil(int src, int colorGraph[]){
    colorGraph[src]=1;
    queue<int> q;
    q.push(src);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        FOR(i,0,G[u].size(),1){
            if(G[u][i]==u) return false;
            int v = G[u][i];
            if(colorGraph[v] == -1){
                colorGraph[v] = 1 - colorGraph[u];
                q.push(v);
            }
            else if (colorGraph[u]==colorGraph[v])
                return false;
        }
    }
    return true;
}

bool isBipartite(){
    int colorGraph[V];
    MEM(colorGraph, -1);
    FOR(i,0,V,1)
        if(colorGraph[i] == -1)
            if(isBipartiteUtil(i,colorGraph) == false)
                return false;

    return true;
}

int main(){
    int t,a,b,bug,interact;
    SCD(t);
    FOR(tc,1,t+1,1){
        SCD(bug);
        SCD(interact);
        FOR(i,0,interact,1){
            SCD(a);
            SCD(b);
            G[a].PB(b);
            G[b].PB(a);
        }
        printf("Scenario #%d:\n", tc);
        if (isBipartite())
            printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");
        FOR(i,0,V,1)
            G[i].clear();
        
    }

    return 0;
}