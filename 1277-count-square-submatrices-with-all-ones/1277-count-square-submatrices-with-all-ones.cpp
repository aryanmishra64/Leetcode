class Solution {
public:
   int n;
   int m;

    int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&dp){
        if(i>=n || j>=m){
            return 0;
        }
        if(matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int right=solve(matrix,i+1,j,dp);
        int down=solve(matrix,i,j+1,dp);
        int dig=solve(matrix,i+1,j+1,dp);

        return dp[i][j]=1+min(right,min(down,dig));


    }
    int countSquares(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int res=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              res+=solve(matrix,i,j,dp);
            }
        }
        return res;
    }
};