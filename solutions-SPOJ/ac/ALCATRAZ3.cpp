#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
  
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef vector<pii> vii;
  
#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
  
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); (a)++)
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back

bool visited[105][105];
int n,m,k,x,y;
char maze[100][100];
bool flag = false;

map<char, pii> direction;

void dfs(pii nowc, int count)
{
    if (flag) return;

    visited[nowc.fi][nowc.se] = true;

    if (nowc.fi == x && nowc.se == y) {
        if (count >= k) {
            printf("YES\n");
            flag = true;
            return;
        }
    }

    if (count == 0) 
        visited[nowc.fi][nowc.se] = false;

    for(auto dir : direction) {
        pii nextc = mp(nowc.fi+dir.se.fi, nowc.se+dir.se.se);
        if (nextc.fi < 0 || nextc.fi >=n || nextc.se < 0 || nextc.se >=m) continue;
        if (visited[nextc.fi][nextc.se]) continue;
        if (maze[nextc.fi][nextc.se] == '*') continue;
        dfs(nextc, count+1);
    }

    visited[nowc.fi][nowc.se] = false;
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%d", &k);
    scanf("%d%d", &x, &y);
    direction['u'] = make_pair(-1, 0);
    direction['d'] = make_pair(1, 0);
    direction['l'] = make_pair(0, -1);
    direction['r'] = make_pair(0, 1);
    FOR(i,0,n) {
        FOR(j,0,m) {
            scanf("%s", &maze[i][j]);
            visited[i][j]=false;
        }
    }
    x--;
    y--;
    dfs(mp(x,y), 0);
    if (!flag)
        printf("NO\n");
    return 0;
}