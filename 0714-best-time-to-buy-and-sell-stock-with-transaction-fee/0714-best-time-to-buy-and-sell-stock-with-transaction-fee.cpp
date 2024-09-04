class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                dp[ind][buy] = max(-prices[ind]+dp[ind+1][0],
                                  0+dp[ind+1][1]);
                }
                else {
                    dp[ind][buy]=max(prices[ind]-fee +dp[ind+1][1],
                                    0+dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};