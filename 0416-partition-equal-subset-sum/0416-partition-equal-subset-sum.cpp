class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        
        if(sum%2!=0) return false;
        
        int k =sum/2;
        
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(nums[0]<=k)
        {
            dp[0][nums[0]]=true;
        }
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                 bool notTake= dp[ind-1][target];
                bool take=false;
                if(nums[ind]<=target){
                    take=dp[ind-1][target-nums[ind]];
                    
                }
                dp[ind][target]= notTake || take;
            }
        }
        return dp[n-1][k];
    }
    
    
    
    
    
    
    
    
    
    
    
};