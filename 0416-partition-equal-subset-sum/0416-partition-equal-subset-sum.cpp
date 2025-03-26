class Solution {
public:
    bool solve(int ind, int sum, vector<int>& arr, vector<vector<int>>&dp) {
        // Base case: If we've gone through all elements
        if(sum==0){
            return true;
        }
        if(ind==0){
            return (arr[0]==sum);
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        // Not taking the current element
        bool notTake = solve(ind - 1, sum, arr,dp);
        
        // Taking the current element
        bool take =false;
        
        if(sum>=arr[ind]){
            take=solve(ind-1,sum-arr[ind],arr,dp
            );
        }
        
        return dp[ind][sum]=notTake || take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int  sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];

        }
        if(sum%2==1){
            return false;
        }
        else {
            sum=sum/2;
            vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        return solve(n-1, sum, nums,dp);
        }

        
        
    }
};