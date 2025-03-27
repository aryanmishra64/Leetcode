class Solution {
public:
   

      
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
       

        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));

        for(int tar=0;tar<=amount;tar++){

            if(tar%coins[0]==0){
                dp[0][tar]=tar/coins[0];
            }
            else{
                dp[0][tar]=INT_MAX;
            }     
        }

        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){

                int notake=0+dp[ind-1][tar];
                 int take=1e8;
                if(tar>=coins[ind]){
                  take=1+dp[ind][tar-coins[ind]];
                        }
                     dp[ind][tar]=min(notake,take);   


            }
        }

        if(dp[n-1][amount]>=1e8){
            return -1;
        }


        return dp[n-1][amount];




       
    }
};