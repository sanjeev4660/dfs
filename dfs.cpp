#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[10000];
vector<int>vis[10000];


void dfs(int node){
    vis[node]=1;
    cout<<node<" ";

    for(auto it: adj[node]){
        if(vis[it]==0){
            dfs(it);
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);   
        adj[v].push_back(u);     
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }
}
