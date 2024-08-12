class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0){
                dp[0][target]=target/coins[0];
            }
            else{
                dp[0][target]=1e9;
            }
        }
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){
                int notTake=0+dp[ind-1][tar];
                
                int Take=INT_MAX;
                if(coins[ind]<=tar){
                    Take=1+dp[ind][tar-coins[ind]];
                }
                dp[ind][tar]=min(Take,notTake);
            }
        }
        int ans = dp[n-1][amount];
        if(ans>=1e9) return -1;
        
        return ans;
        
        
        
    }
};