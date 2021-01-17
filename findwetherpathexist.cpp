class Solution {
public:

int bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m){
    queue<pair<int,int>>q;
    q.push({i,j});
    
    vis[i][j]=1;
    
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    
    while(!q.empty()){
        auto k=q.front();
        q.pop();
        int x=k.first;
        int y=k.second;
        
        for(int i=0;i<4;i++){
            int newx=dx[i]+x;
            int newy=dy[i]+y;
            
            if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]!=0 && vis[newx][newy]==0 ){
                if(grid[newx][newy]==2){
                   return 1;
                }
                else {
                    vis[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
        }
        
    }
    return 0;
    
}
    bool is_Possible(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(bfs(i,j,grid,vis,n,m)){
                        return true;
                    }
                  
                }
            }
        }
        return false;
    }
    
};