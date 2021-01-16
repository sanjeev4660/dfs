class Solution {
public:
  
int count=0;
void bfs(int i,int j,vector<vector<char>> &a, vector<vector<int>> &vis,int n,int m){
    queue<pair<int,int>>q;
    q.push({i,j});
    
    vis[i][j]=1;
    int dx[]={0,+1,0,-1,-1,+1,-1,+1};
    int dy[]={+1,0,-1,0,+1,+1,-1,-1};
    while(!q.empty()){
        auto k=q.front();
        q.pop();
        int x=k.first;
        int y=k.second;
        for(int i=0;i<8;i++){
            int newx=dx[i]+x;
            int newy=dy[i]+y;
            if(newx>=0 && newx<=n && newy>=0 && newy<=m && a[newx][newy]=='1' && vis[newx][newy]==0){
                vis[newx][newy]=1;
                q.push({newx,newy});
            }
        }
    }
}
 
int numIslands(vector<vector<char>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]=='1' && vis[i][j]==0){
                count++;
                bfs(i,j,grid,vis,n,m);
               }
            }
        }
    return count;
    
        }

        
    
};