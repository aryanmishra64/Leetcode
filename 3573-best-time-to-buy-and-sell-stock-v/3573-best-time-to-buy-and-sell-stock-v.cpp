class Solution {
public:
    long long solve(int ind,int status,int k,vector<int>&prices,  vector<vector<vector<long long>>>&dp){
        if(k==0){
            return 0;
        }
        if(ind==prices.size()-1){
            if(status==0) return 0;
            if(status==1) return prices[ind];
            return -prices[ind];

        }
        if(dp[ind][status][k]!=INT_MIN) return dp[ind][status][k];
        long long ans=INT_MIN;

        ans=max(ans,solve(ind+1,status,k,prices,dp));
        if(status==0){
            ans=max(ans,-prices[ind]+solve(ind+1,1,k,prices,dp));
            ans=max(ans,prices[ind]+solve(ind+1,2,k,prices,dp));

        }
        else if(status==1){
            ans=max(ans,prices[ind]+solve(ind+1,0,k-1,prices,dp));
        }
        else {
            ans=max(ans,-prices[ind]+solve(ind+1,0,k-1,prices,dp));
        }
        return dp[ind][status][k]=ans;

    }

    
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(3,vector<long long>(k+1,INT_MIN)));
        return solve(0,0,k,prices,dp);
    }
};