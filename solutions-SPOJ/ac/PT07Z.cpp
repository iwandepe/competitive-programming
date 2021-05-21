/**
 * Longest path in a tree
 * 
 * Solved with diameter of a tree using DFS
 * 
 * Solved at 18/01/2021
 * 
 **/

#include <bits/stdc++.h>
using namespace std;

int x;

void dfsUtil(int node, int count, bool visited[], int&maxCount, vector<int>v[]){
    visited[node]=true;
    count++;
    for(auto& i : v[node]){
        if (!visited[i]){
            if (count >= maxCount){
                maxCount=count;
                x=i;
            }
            dfsUtil(i, count, visited, maxCount, v);
        }
    }
}

void dfs(int node, int n, vector<int>v[], int&maxCount){
    bool visited[n+1];
    int count=0;
    memset(visited, false, sizeof(visited));
    dfsUtil(node, count, visited, maxCount, v);
}

int diameter(vector<int> v[], int n){
    int maxCount = INT_MIN;
    dfs(1,n,v,maxCount);
    dfs(x,n,v,maxCount);
    return maxCount;
}

int main(){
    int n;
    cin>>n;
    vector<int> v[n+1];
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<diameter(v, n)<<endl;
    return 0;
}