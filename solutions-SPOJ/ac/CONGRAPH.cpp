#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vii;

vii vec[800008];
bool visited[800008];

#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); (a)++)
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back

void dfs(int curVertex)
{
    visited[curVertex] = 1; 
    for (int i = 0 ; i < vec[curVertex].size() ; i++) 
    {
        int nextVertex = vec[curVertex][i];
        if (!visited[nextVertex]) 
        {
            dfs(nextVertex);
        }
    }
}
int main() {
    int n,m,a,b,count;
    cin>>n>>m;
    FOR(i,0,m) {
        cin>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
    }
    count=0;
    FOR(i,0,n) {
        if(!visited[i]) {
            count++;
            dfs(i);
        }
    }
    printf("%d\n", count-1);
    return 0;
}