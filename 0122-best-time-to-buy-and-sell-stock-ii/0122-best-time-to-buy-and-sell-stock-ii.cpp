class Solution {
public:
    int solve(int ind,int buy,vector<int>& prices,vector<vector<int>>&dp){
        if(ind==prices.size()){
            return 0;
        }

        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }

        int profit=0;
        if(buy){
            profit=max(-prices[ind]+solve(ind+1,0,prices,dp),0+solve(ind+1,1,prices,dp));

        }
        else {
            profit=max(prices[ind]+solve(ind+1,1,prices,dp),0+solve(ind+1,0,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int buy=1;
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
       int ans= solve(0,buy,prices,dp);
       return ans;
    }
};