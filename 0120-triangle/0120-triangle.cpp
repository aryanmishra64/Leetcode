class Solution {
public:
    int n;
    int solve(int i,int j,vector<vector<int>>& arr,vector<vector<int>>&dp){
        if(i==n-1){
            return arr[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int down=arr[i][j]+solve(i+1,j,arr,dp);
        int dig=arr[i][j]+solve(i+1,j+1,arr,dp);

        return dp[i][j]=min(down,dig);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        n=triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        
     int ans=   solve(0,0,triangle,dp);

     return ans;

    }
};