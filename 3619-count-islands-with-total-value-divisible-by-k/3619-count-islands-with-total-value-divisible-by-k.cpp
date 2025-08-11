class Solution {
public:

    vector<pair<int,int>>dir={{-1,0},{0,+1},{+1,0},{0,-1}};

    int dfs(int i,int j,vector<vector<bool>>&vis,int n,int m,vector<vector<int>>& grid){
        vis[i][j]=true;

        long long sum=grid[i][j];

        for(auto it:dir){

            int nrow=i+it.first;
            int ncol=j+it.second;

            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]!=0 && vis[nrow][ncol]==false){
                sum+=dfs(nrow,ncol,vis,n,m,grid);
            }

            

        }
        return sum;


    }
    int countIslands(vector<vector<int>>& grid, int k) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    continue;
                }
                else if(vis[i][j]==false){
                    int val=dfs(i,j,vis,n,m,grid);

                    if(val%k==0){
                        cnt++;
                    }


                }
            }
        }
        return cnt;
        
    }
};