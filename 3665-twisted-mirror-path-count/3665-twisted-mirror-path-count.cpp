class Solution {
public:
    int mod=1e9+7;
    long long dp[500][500][3];

    long long func(int i,int j,vector<vector<int>> &grid,int dir){
        // Base case: reached destination cell
        if(i==n-1 && j==m-1) return 1LL;

        // Out of bounds
        if(i>=n || j>=m) return 0LL;

        // Already computed
        if(dp[i][j][dir]!=-1) return dp[i][j][dir];

        // If current cell contains a mirror
        if(grid[i][j]==1){  
            if(dir==0){ // came from left (moving right before hitting mirror)
                // mirror reflects right → down
                return dp[i][j][dir]=func(i+1,j,grid,1)%mod;
            }else{ // came from up (moving down before hitting mirror)
                // mirror reflects down → right
                return dp[i][j][dir]=func(i,j+1,grid,0)%mod;
            }
        }

        // If normal cell (no mirror), can move right or down
        long long right=func(i,j+1,grid,0)%mod; 
        long long down=func(i+1,j,grid,1)%mod;

        return dp[i][j][dir]=(right+down)%mod;
    }

    int n,m;
    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));

        // Start at (0,0) with no prior direction (dir=2 means 'start')
        return func(0,0,grid,2)%mod;
    }
};