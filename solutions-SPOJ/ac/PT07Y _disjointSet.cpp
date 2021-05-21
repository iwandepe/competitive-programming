/**
 * Check graph is a tree or not
 * with disjoint set
 * 
 * 19 Jan 2021
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

void initDSU(int parent[], int n){
    for (int i=1; i<=n; i++){
        parent[i]=i;
    }
}

int find(int parent[], int v){
    if (v==parent[v])
        return v;
    return find(parent, parent[v]);
}

void Union(int parent[], int a, int b){
    parent[a]=b;
}

bool isCyclic(vector<int>v[], int n)
{
    int parent[n+1];
    initDSU(parent, n);

    for (int i=1; i<=n; i++){
        for (auto& j : v[i]){   
            int x = find(parent, i);
            int y = find(parent, j);

            if (x == y){
                cout<<i<<" " <<j<<endl;
                return true;
            }
            
            Union(parent, x, y);
        }
    }
    return false;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>v[n+1];
    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    if (isCyclic(v, n))
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}