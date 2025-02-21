#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    int help(int i, int j, int rem, int n, int m, vvi&coins,  vector<vvi>&dp){
        if(i==n-1 && j==m-1){
            if(coins[i][j]<0){
                return (rem>0) ? 0 : coins[i][j];
            }
            else {
                return coins[i][j];
            }
        }

        if(i>=n || j>=m)
        return -1e9;

        if(dp[i][j][rem] !=INT_MIN)
        return dp[i][j][rem];

        int right=-1e9,down=-1e9;

        if(coins[i][j]<0){
            if(rem>0){
                right = help(i,j+1,rem-1,n,m,coins,dp);
                down = help(i+1,j,rem-1,n,m,coins,dp);
            }
        }
        right = max(right,coins[i][j]+help(i,j+1,rem,n,m,coins,dp));
        down = max(down, coins[i][j]+help(i+1,j,rem,n,m,coins,dp));

        return dp[i][j][rem]=max(right,down);

        
    }



    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size(),m=coins[0].size();

        vector<vvi>dp(n+1,vvi(m+1,vi(3,INT_MIN)));

        return help(0,0,2,n,m,coins,dp);

    }
};