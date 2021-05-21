/**
 * Check graph is a tree or not
 * with DFS
 * 
 * 19 Jan 2021
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int node, bool visited[], vector<int>v[], int parent){
    visited[node] = true;

    for(auto& i : v[node]){
        if (!visited[i]){
            if (isCyclicUtil(i, visited, v, node))
                return true;
        }
        else if (i != parent)
            return true;
    }

    return false;
}

bool isCyclic(vector<int>v[], int n){
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    for (int i=1; i<=n; i++){
        if(!visited[i])
            if (isCyclicUtil(i, visited, v, -1))
                return true;
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
        v[b].push_back(a);
    }
    if (isCyclic(v,n))
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}