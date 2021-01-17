#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[10000];
vector<int>vis[10000];
bool dfs(int node,int par){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,node)) return true;
        }
        else if(vis[it]==1 && it!=par){
            return true;
        }
    }
    return false;

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
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,0)==true){
                flag=true;
                break;
            }
        }
    }
    if(flag==true){
        cout<<"cycle detected";
    }
    else{
        cout<<"no cycle";
    }

}
