class Solution {
public:
    int solve(int ind,int n, vector<int>&dp){
        if(ind==n){
            return 1;
        }
        if(ind>n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int take1=solve(ind+1,n,dp);
        int take2=solve(ind+2,n,dp);

        return dp[ind]=take1+take2;
    }


    int climbStairs(int n) {
        
        int ind=0;
        vector<int>dp(n+1,-1);
       return solve(0,n,dp);
    }
};