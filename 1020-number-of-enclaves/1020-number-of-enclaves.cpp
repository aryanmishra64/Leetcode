class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;

        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid);
            }

        }
    }



    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
     vector<vector<int>>vis(n,vector<int>(m,0));


       //first and last row 
       
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,vis,grid);
            }



        }
        // first col and last col
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,n-1,vis,grid);
            }
        }

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;


       
    }
};