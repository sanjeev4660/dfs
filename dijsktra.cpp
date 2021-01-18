#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>>adj[10000];

void dijkrta(int node,int n){
    int inf=1e9;
    vector<int>dist(n,inf);
    dist[1]=0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<int>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto k=pq.top();
        pq.pop();
        int dis=k.first;
        int node=k.second;

        for(auto it:adj[node]){
            int x=it.first;
            int v=it.second;

            if(x+dis<dist[v]){
                dist[v]=x+dis;
                pq.push({x+dis,v});
            }
        }

    }

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }

}
int main() {
    int n,m,wt;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});

    }
    dijkrta(1,n);

}
