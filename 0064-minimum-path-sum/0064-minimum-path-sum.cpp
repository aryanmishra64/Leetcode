class Solution {
public:
    int n,m;

    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(i<0 || i>=m || j<0 || j>=n){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int down=grid[i][j]+solve(i+1,j,grid,dp);
        int right=grid[i][j]+solve(i,j+1,grid,dp);

        return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {

        m=grid.size();
        n=grid[0].size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));


        
        int i=0;
        int j=0;

       int ans= solve(i,j,grid,dp);

       return ans;

    }
};