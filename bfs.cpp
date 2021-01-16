#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[10000];
vector<int>vis[10000];

void bfs(int node){

    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj[node]){
            if(vis[it]==0){
                vis[it]=1;
                q.push(it);
            }
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
    bfs(1);
}